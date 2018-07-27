open ReactBigCalendar;

type state = {
  events: array(BigCalendar.eventItem)
};

type action =
  | UpdateEvents(array(BigCalendar.eventItem));

let component = ReasonReact.reducerComponent("Basic");

let make(children) {
  ...component,
  initialState: () => {
    events: [||]
  },
  reducer: (action, state) => switch action {
    | UpdateEvents(events) => ReasonReact.Update({...state, events}) 
  },
  render: (self) => {
    <BigCalendar>
    </BigCalendar>;
  }
}
