open ReactBigCalendar;
open MomentRe;

type state = {
  events: array(BigCalendar.eventItem)
};

type action =
  | UpdateEvents(array(BigCalendar.eventItem));

let component = ReasonReact.reducerComponent("Basic");

let make(children) {
  ...component,
  initialState: () => {
    events: [|
      BigCalendar.event(
        ~title="All Day Event",
        ~start=Moment.toDate(momentNow()),
        ~end_=Moment.toDate(momentNow()),
        ~allDay=true,
        ()
      )
    |]
  },
  reducer: (action, state) => switch action {
    | UpdateEvents(events) => ReasonReact.Update({...state, events}) 
  },
  render: (self) => {
    <div className="calendar-container">
      <BigCalendar
        events=self.state.events
        eventPropGetter=((eventProp) => {Js.log(eventProp); {"className": "has-background-danger"}})
        >
      </BigCalendar>
    </div>;
  }
}
