/* The State */
type state = {
  count: int,
  showCounter: bool
}

/* The Action */
type action =
  | Increment
  | Decrement
  | ToggleCounter;

/* Creates a Counter reducer component */
let component = ReasonReact.reducerComponent("Counter");

let make = (_children) => {
  ...component,
  
  initialState: () => { count: 0, showCounter: false },
  reducer: (action, state) =>
    switch(action) {
      | Increment => ReasonReact.Update({...state, count: state.count + 1})
      | Decrement => ReasonReact.Update({...state, count: state.count - 1})
      | ToggleCounter => ReasonReact.Update({...state, showCounter: !state.showCounter})
    },
  
  render: self => {
    <div style={ReactDOMRe.Style.make(~width="100px", ~textAlign="center", ())}>
      <div style={ReactDOMRe.Style.make(~marginBottom="20px", ())}>
        <button onClick={_event => self.send(ToggleCounter)}
                style={ReactDOMRe.Style.make(~width="100px", ~height="25px", ())}>
          {ReasonReact.string(
            self.state.showCounter ?
            "Hide Counter" : "Show Counter"
            )} </button>
      </div>

      {self.state.showCounter ? 
        (
          <div>
            <button onClick={_event => self.send(Increment)}
                    style={ReactDOMRe.Style.make(~width="50px", ~height="25px", ())}>
              {ReasonReact.string("+")} </button>
            <h2 style={ReactDOMRe.Style.make(~width="100px", ~textAlign="center", ())}> 
              {ReasonReact.string( string_of_int(self.state.count ))} </h2>
            <button onClick={_event => self.send(Decrement)}
                    style={ReactDOMRe.Style.make(~width="50px", ~height="25px", ())}>
              {ReasonReact.string("-")} </button>
          </div>
        ) : ReasonReact.null
      }
    </div>
  }
};