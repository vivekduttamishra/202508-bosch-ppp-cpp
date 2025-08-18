

var p= new Object();
//now I have an object 'p' but withiout any properties or behavior

p.name="Vivek";  //now p has a name.
p.age=100; 


p.eat= function(food){
    console.log(`${this.name} is eating ${food}`);
}

p.move=function(from,to){
    console.log(`${this.name} is moving from ${from} to ${to}`);
}

p.eat("pizza");
p.move("home", "office");