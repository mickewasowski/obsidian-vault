---
aliases:
context:
---

#wip

# NestJs

ad

---


### Controllers

@Controller decorator is required to define a basic controller.
Route path is optional:
``` js
@Controller('cats') => cats is route path
```

``` js
@Get('breed') => this results in a GET request at /cats/breed
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


