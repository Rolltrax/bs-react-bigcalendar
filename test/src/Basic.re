open BsReactBigcalendar;
open MomentRe;

[@react.component]
let make = () => {
  let events = [|
    BigCalendar.event(
      ~title="All Day Event",
      ~start=Moment.toDate(momentNow()),
      ~end_=Moment.toDate(momentNow()),
      ~allDay=true,
      ()
    )
  |];
  <div className="calendar-container">
    <BigCalendar
      localizer=BigCalendar.localizer
      events
      eventPropGetter=((eventProp) => {"className": "has-background-danger"})
      >
    </BigCalendar>
  </div>;
}