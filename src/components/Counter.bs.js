// Generated by BUCKLESCRIPT VERSION 4.0.0, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");

var component = ReasonReact.reducerComponent("Counter");

function make() {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (self) {
              var match = self[/* state */1][/* showCounter */1];
              var match$1 = self[/* state */1][/* showCounter */1];
              return React.createElement("div", {
                          style: {
                            textAlign: "center",
                            width: "100px"
                          }
                        }, React.createElement("div", {
                              style: {
                                marginBottom: "20px"
                              }
                            }, React.createElement("button", {
                                  style: {
                                    height: "25px",
                                    width: "100px"
                                  },
                                  onClick: (function () {
                                      return Curry._1(self[/* send */3], /* ToggleCounter */2);
                                    })
                                }, match ? "Hide Counter" : "Show Counter")), match$1 ? React.createElement("div", undefined, React.createElement("button", {
                                    style: {
                                      height: "25px",
                                      width: "50px"
                                    },
                                    onClick: (function () {
                                        return Curry._1(self[/* send */3], /* Increment */0);
                                      })
                                  }, "+"), React.createElement("h2", {
                                    style: {
                                      textAlign: "center",
                                      width: "100px"
                                    }
                                  }, String(self[/* state */1][/* count */0])), React.createElement("button", {
                                    style: {
                                      height: "25px",
                                      width: "50px"
                                    },
                                    onClick: (function () {
                                        return Curry._1(self[/* send */3], /* Decrement */1);
                                      })
                                  }, "-")) : null);
            }),
          /* initialState */(function () {
              return /* record */[
                      /* count */0,
                      /* showCounter */false
                    ];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, state) {
              switch (action) {
                case 0 : 
                    return /* Update */Block.__(0, [/* record */[
                                /* count */state[/* count */0] + 1 | 0,
                                /* showCounter */state[/* showCounter */1]
                              ]]);
                case 1 : 
                    return /* Update */Block.__(0, [/* record */[
                                /* count */state[/* count */0] - 1 | 0,
                                /* showCounter */state[/* showCounter */1]
                              ]]);
                case 2 : 
                    return /* Update */Block.__(0, [/* record */[
                                /* count */state[/* count */0],
                                /* showCounter */!state[/* showCounter */1]
                              ]]);
                
              }
            }),
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

exports.component = component;
exports.make = make;
/* component Not a pure module */
