module BigCalendar = {
  [@bs.module "react-big-calendar"]
  external reactClass : ReasonReact.reactClass = "Calendar";

  type calendarView =
    | Month
    | Week
    | WorkWeek
    | Day
    | Agenda;
  
  type eventItem = {.
    "title": string,
    "start": 'a.Js.Nullable.t('a),
    "end": 'a.Js.Nullable.t('a),
    "allDay?": Js.Nullable.t(bool)
    /* TODO: Find a way to implement resource tag */
  };

  let event(~title, ~start = ?, ~_end = ?, ~allDay = ?, ()) {
    "title": title,
    "start": Js.Nullable.fromOption(start),
    "end": Js.Nullable.fromOption(_end),
    "allDay?": Js.Nullable.fromOption(allDay)
  };

  let make = 
  (
  ~elementProps: option(Js.t({..})) = ?,
  ~date: option(Js.t({..})) = ?,
  ~view: option(calendarView) = ?,
  ~defaultView: option(calendarView) = ?,
  ~events: option(Js.Array.t(eventItem)) = ?,
  ~titleAccessor: option(eventItem => string) = ?,
  ~tooltipAccessor: option(eventItem => string) = ?,
  ~allDayAccessor: option(eventItem => string) = ?,
  ~startAccessor: option(eventItem => Js.t({..})) = ?,
  ~endAccessor: option(eventItem => Js.t({..})) = ?,
  ~resourceAccessor: option(eventItem => Js.t({..})) = ?,
  ~resources: option(array(Js.t({..}))) = ?,
  ~resourceIdAccessor: option(Js.t({..}) => Js.t({..})) = ?,
  ~resourceTitleAccessor: option(Js.t({..}) => Js.t({..})) = ?,
  
  ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass
  );
};