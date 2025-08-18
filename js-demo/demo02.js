

function createPerson(name, age) {
    var p = new Object();
    //now I have an object 'p' but withiout any properties or behavior

    p.name = name;  //now p has a name.
    p.age = age;


    p.eat = function (food) {
        console.log(`${this.name} is eating ${food}`);
    }

    p.move = function (from, to) {
        console.log(`${this.name} is moving from ${from} to ${to}`);
    }

    return p;
}

let vivek= createPerson("Vivek", 100);
let prabhat = createPerson("Prabhat", 200);

vivek.eat("Pizza");
vivek.move("Home", "Office");
prabhat.eat("Burger");
prabhat.move("Office", "Home");