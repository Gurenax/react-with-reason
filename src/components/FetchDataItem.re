let component = ReasonReact.statelessComponent("FetchDataItem");

let make = (~data: FetchData.data, _children) => {
  ...component,
  render: _self =>
    <div key=data.full_name>
      <a href=data.html_url>
        <h2>{ReasonReact.string(data.full_name)}</h2>
      </a>
      {ReasonReact.string(string_of_int(data.stargazers_count) ++ " stars")}
    </div>
};