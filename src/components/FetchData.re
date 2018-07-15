type data = {
  full_name: string,
  stargazers_count: int,
  html_url: string
};

let parseDataJson = (json: Js.Json.t): data =>
  Json.Decode.{
    full_name: field("full_name", string, json),
    stargazers_count: field("stargazers_count", int, json),
    html_url: field("html_url", string, json)
  };

let parseDataResponseJson = json =>
  Json.Decode.(field("items", array(parseDataJson), json));

let githubSearchUrl = "https://api.github.com/search/repositories?q=topic%3Areasonml&type=Repositories";

let fetchTheData = () =>
  Js.Promise.(
    Bs_fetch.fetch(githubSearchUrl)
      |> then_(Bs_fetch.Response.text)
      |> then_(
        jsonText =>
          resolve(parseDataResponseJson(Js.Json.parseExn(jsonText)))
      )
  );