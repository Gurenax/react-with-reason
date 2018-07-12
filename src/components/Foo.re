/* This is a Foo reason file - example of Props forwarding*/
let component = ReasonReact.statelessComponent("Foo");

let make = (~name, ~age=?, _children) => {
  ...component,
  render: (_self) => {
    switch(age) {
      |None => <p>{ReasonReact.string("My name is " ++ name ++ ".")}</p>
      |Some(age) => <p>{ReasonReact.string("My name is " ++ name ++ " and I am " ++ string_of_int(age) ++ " years old.")}</p>
    };
  }
};