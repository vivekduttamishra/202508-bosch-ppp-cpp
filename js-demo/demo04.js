function personMoves(from, to) {
        console.log(`${this.name} is moving from ${from} to ${to}`);
}

function createPerson(name, age) {
    var p = new Object();
    //now I have an object 'p' but withiout any properties or behavior

    p.name = name;  //now p has a name.
    p.age = age;


    p.eat = function (food) {
        console.log(`${this.name} is eating ${food}`);
    }

    p.move = personMoves;

    return p;
}


function teachDriving(person, veichle){
    if(person.age<18){
        return console.log(`${person.name} is too young to drive`);
    }

    if(person.liecences){
        if(!person.liecences.includes(veichle)){
            person.liecences.push(veichle);
        }
    } else{
        person.liecences = [veichle];
        person.drive=function( veichle){
            if(this.liecences.includes(veichle)){
                console.log(`${this.name} is driving a ${veichle}`);
            }else{
                console.log(`${this.name} does not have a licence to drive a ${veichle}`);
            }

        }
    }

}


let vivek= createPerson('Vivek', 100);
let ankit = createPerson('Ankit', 17);

teachDriving(vivek, 'car');
teachDriving(ankit, 'car');

vivek.drive('car'); //viveks is allowed to drive a car
vivek.drive('truck'); //vivek knows to drive but not allowed to drive a truck
try{

    ankit.drive('car'); //doesn't have drive method.
}catch(e){
    console.log(e.message);
}

ankit.age=18; //ankit is now 18.
teachDriving(ankit, 'bike');

ankit.drive('bike'); //ankit is now allowed to drive a bike
ankit.drive('car');

console.log('vivek.eat===ankit.eat',vivek.eat===ankit.eat);

console.log('vivek.move===ankit.move',vivek.move===ankit.move);