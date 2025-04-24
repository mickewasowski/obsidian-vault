---
aliases:
context:
- "[[NestJS]]"
- "[[JavaScript]]"
---

#wip

# NestJS Controllers

Controllers are responsible for handling incoming requests and sending responses back to the client.

---

## Controllers

Controllers are responsible for handling incoming requests and sending responses back to the client.
The routing mechanism determines which controller will handle each request.
Controllers are implemented with classes and decorators. Decorators link classes with the necessary metadata, allowing Nest to create a routing map.

> [!Tip] You can use ``` nest g resource [name] ``` to quickly create a CRUD controller with built-in validation.

You can provide an optional controller path and the whole path would be something like /cats/breed

``` js
@Controller('cats') //cats is a route path and is optional
export class CatsController {
  @Get()
  findAll(): string {
    return 'This action returns all cats';
  }
  @Get('breed') //breed is optional method decocator path
  findAllBreeds(): string {
    return 'This action returns all cat breed!';
  }
}
```


``` js 
//This is perfectly fine code! The position of each function doesn't matter in this case
@Controller('cats')
export class CatsController {
  @Get()
  findAll(): string {
    return 'This action returns all cats';
  }
  @Get('breed')
  findAllBreeds(): string {
    return 'This action returns all cats breeds';
  }
}
```

We can also specify the response status code for the handler method:
``` js
@Controller('cats')
export class CatsController {
  @Get()
  @HttpCode(204) // provided explicitely
  findAll(): string {
	return 'This action returns all cats';
  }
}
```

> [!warning] 
> When using the default Nest response handling you don't need to think about serializing objects. Simply return the value (object, array) and Nest will serialize it automatically under the hood. If the value is of primitive type (string, number, boolean) Nest will not try to serialize it and it will simply return the value.

You can access the request object with the @Req decorator in the handler method's signature:
``` js
@Controller('cats')
export class CatsController {
  @Get()
  findAll(@Req() request: Request): string {
    return 'This action returns all cats';
  }
}
```

You can also use decorators like @Body or @Query(key?: string) to access the body of the request, or the query parameters.

You can also have a route wildcards:
``` js
@Get('abcd/*') // this will handle any routes that start with abcd/

@Get('ab{*test}cd/') // test is naming the wildcard because it is in the middle of the route, Express requires the wildcard to be named when it is in the middle of the name, Fastify does not support this
```


You can also specify custom response headers:
``` js
@Post()
@Header('Cache-Control', 'no-store')
```

You can also redirect to a specific URL:
``` js
@Get()
@Redirect('https://www.example.com', 301) //takes 2 arguments, the URL and a status code, both are optional
```


Returned values will override any arguments passed to the Redirect:
``` js
@Get()
@Redirect('https://www.example.com', 301)
getDocs(@Query('version') version) {
	if (version > 5) {
		return { url: 'test url here' }; // this url will override the provided one in the Redirect brackets
	}
}
```

Route parameters:
``` js
@Get(':id')
findOne(@Param() params: any) {
	console.log(params.id);
}

//or you can specify a parameter name
@Get(':id')
findOne(@Param('id') id: string) {
	return `something ${id}`;
}
```

> [!tip] Routes with parameters should be declared after static routes. This prevents parameterized paths from intercepting traffic designated for static paths. 


#### Sub-domain routing
The @Controller decorator can take a host option to require that the HTTP host of the incoming request matches some specific value:
``` js
@Controller({ host: 'admin.example.com' })
export class AdminController {
  @Get()
  index(): string {
    return 'Admin page';
  }
}
```
