/* The State */
type state = {
  githubData: option(array(FetchData.data))
}

/* The Action */
type action =
  | Loaded(array(FetchData.data));

/* Creates a Counter reducer component */
let component = ReasonReact.reducerComponent("Fetch");

let make = (_children) => {
  ...component,
  
  initialState: () => { githubData: None },
  didMount: self => {
    FetchData.fetchTheData() 
      |> Js.Promise.then_(result => {
          /* Js.log(result); */
          self.send(Loaded(result));
          Js.Promise.resolve();
        })
      |> ignore;    
  },
  
  reducer: (action, state) =>
    switch(action) {
      | Loaded(loadedData) => {
        ReasonReact.Update({githubData: Some(loadedData)})
      }
    },
  
  render: (self) => {
    let githubDataItem =
      switch(self.state.githubData) {
        |Some(data) => ReasonReact.array(
            Array.map(
              (data: FetchData.data) =>
                /* <h2 key={data.full_name}>
                  {ReasonReact.string(data.full_name)}</h2>, */
                <FetchDataItem key=data.full_name data=data />,
              data
            )
          )
        |None => ReasonReact.string("Loading")
      };
    
    <div>
      <h1>{ReasonReact.string("Reason Projects from GitHub")}</h1>
      {githubDataItem}
    </div>

  }
};