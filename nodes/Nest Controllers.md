---
aliases:
context:
---

#wip

# Nest Controllers


---
### State sharing
In NestJS, state sharing typically refers to sharing data or state between different parts of an application, such as modules, services, or controllers.

How to achieve it:
1. Dependency Injection (DI) - NestJS's DI system allows services (providers) to be shared across modules. A service instantiated in one module can be injected into another if exported and imported properly.
2. Module Scope - by default, providers are singleton-scoped (shared across the app). However, you can also use request-scoped providers for per-request state.
3. Global Modules - A module marked with @Global() makes its providers available app-wide without explicit imports.
4. Request/Response Objects - State can be passed via request objects (e.g. using middleware, guards, or interceptors to attach data)

``` javascript
// Shared service
@Injectable()
export class SharedService {
  state: string = "Hello!";
}

// Module A exports the service
@Module({
  providers: [SharedService],
  exports: [SharedService],
})
export class ModuleA {}

// Module B can now inject SharedService
@Module({
  imports: [ModuleA],
  controllers: [AppController],
})
export class ModuleB {}
```



### Request payloads

Let's introduce the @Body decorator.
First we need to define a DTO (data transfer object) schema. It specifies how data should be sent over the network. We can define it either with a TS interface or a simple class. It is recommended to use classes here because classes are part of the JS ES6, so they remain intact as real entities in the compiled JS. In contrast, TS interfaces are removed during [[transpilation]].


``` javascript
// create-cat.dto.ts
export class CreateCatDto {
  name: string;
  age: number;
  breed: string;
}
```

``` javascript
// CatsController
@Post()
async create(@Body() createCatDto: CreateCatDto) {
  return 'This action adds a new cat';
}
```







