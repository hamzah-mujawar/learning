## The prototype:
- All objects in JavaScript have a prototype that its children can inherit.
```js
function Player(name, marker){
    this.name = name;
    this.marker = marker;
    this.sayName = function() {
        console.log(this.name)
    };
}

const player1 = new Player('steve', 'X');
const player2 = new Player('also steve', 'O');

Player.prototype.sayHello = function () {
    console.log("Hello I'm a player");
};

player1.sayHello();
player2.sayHello();

```
- Object.prototype -> Player.prototype -> Player objects (player1, player2)
- Every `prototype` object inherits from `Object.prototype` by default.

- You can `.setPrototypeOf` an object for example you can do:
    `Object.setPrototypeOf(Player.prototype, Person.prototype)`
and then when you do `Object.getProtypeOf(Player.prototype)` it will return 
`Person.prototype`. This way we can access both functions from `Player` and `Person` prototypes.

```js
function Person(name){
    this.name = name;
}

Person.prototype.sayName = function() {
    console.log(`Hello, I'm ${this.name}!`);
};

function Player(name, marker){
    this.name = name;
    this.marker = marker;
}

Player.prototype.getMarker = function(){
    console.log(`My marker is '${this.marker}'`);
};

Object.getPrototypeOf(Player.prototype);

Object.setPrototypeOf(Player.prototype, Person.prototype);
Object.getPrototypeOf(Player.prototype);


const player1 = new Player('steve', 'X');
const player2 = new Player('also steve', 'O');

player1.sayName();
player2.sayName();

player1.getMarker();
player2.getMarker();

```

Note:
- Make sure you do `Object.setPrototypeOf()` before creating any objects 
as this will cause performance issues

## Writing doesn't use prototype
- The prototype is only used for reading properties, Write/delete 
works directly with the object. 
- Accessor properties are the exception, as assignment is handled
by a setter function. So writing to such a property is actually the 
same as calling a function.
- We can use the built-in method `.hasOwnProperty(key)` to check if the
property is inherited or not.
- this refers to the object we pass in when we call our method. This way
we can modify the states of the inheriting objects but not the parent object.

## Closures:
```js
function makeAdding (firstNumber)
{
    const first = firstNumber;
    return function resulting (secondNumber){
        const second = secondNumber;
        return first + second;
    }
}

const add5 = makeAdding(5);
console.log(add5(2)) // logs 7
```
1) the `makeAdding` function takes an argument, `firstNumber`, declares
a constant `first` with the value of `firstNumber`, and returns another function.
2) when an argument is passed to the resturned function, which we have assigned to 
add5, it returns the result of adding up the number passed earlier to the number passed now.

Functions in JavaScript form closures. A closure refers to the combination of a 
function and the surrounding state in which the function was declared.
This surrounding state in which the function was declared. 

This surrounding state, also called its lexical environment, consists of
any local variables that were in scope at the time of the closure was made.

Here, `add5` is a reference to the `resulting` function, created when the

