ReactDOMRe.renderToElementWithId(<Component1 message="Hello!" />, "index1");

ReactDOMRe.renderToElementWithId(<Component2 greeting="Hello!" />, "index2");

/* Render Greeting component to greeting element */
ReactDOMRe.renderToElementWithId(<Greeting name="Glenn" />, "greeting");

/* Render Foo component to foo element */
ReactDOMRe.renderToElementWithId(<Foo name="Glenn" age=5 />, "foo");
ReactDOMRe.renderToElementWithId(<Foo name="Glenn" />, "fooWithoutAge");