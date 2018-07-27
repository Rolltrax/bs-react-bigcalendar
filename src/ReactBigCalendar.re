open MomentRe;

module BigCalendar = {
  [@bs.module]
  external reactClass : ReasonReact.reactClass = "react-big-calendar/lib/index";

  /* Create a localizer */
  [@bs.module]
  external moment : Js.t({..}) = "moment";

  [@bs.module "react-big-calendar/lib/localizers/moment"]
  external localize : Js.t({..}) => Js.t({..}) = "default";
  let localizer = localize(moment);

  let omap = (f, x) => switch x {
    | Some(y) => Some(f(y))
    | None => None
  };

  type calendarView =
    | Month
    | Week
    | WorkWeek
    | Day
    | Agenda;

  let calendarViewToString = cv => switch cv {
    | Month => "month"
    | Week => "week"
    | WorkWeek => "work_week"
    | Day => "day"
    | Agenda => "agenda"
  };

  type eventItem = {.
    "title": string,
    "start": Js.Nullable.t(Moment.t),
    "end": Js.Nullable.t(Moment.t),
    "allDay": Js.Nullable.t(bool)
    /* TODO: Find a way to implement resource tag */
  };

  let event(~title, ~start = ?, ~end_ = ?, ~allDay = ?, ()) {
    "title": title,
    "start": Js.Nullable.fromOption(start),
    "end": Js.Nullable.fromOption(end_),
    "allDay": Js.Nullable.fromOption(allDay)
  };

  type range = {.
    "start": Moment.t,
    "end": Moment.t
  }

  let make =
  (
    ~elementProps: option(Js.t({..})) = ?,
    ~date: option(Js.t({..})) = ?,
    ~view: option(calendarView) = ?,
    ~defaultView: option(calendarView) = ?,
    ~events: option(Js.Array.t(eventItem)) = ?,
    ~titleAccessor: option(string) = ?,
    ~tooltipAccessor: option(string) = ?,
    ~allDayAccessor: option(string) = ?,
    ~startAccessor: option(string) = ?,
    ~endAccessor: option(string) = ?,
    ~resourceAccessor: option(string) = ?,
    ~resources: option(array(Js.t({..}))) = ?,
    ~resourceIdAccessor: option(Js.t({..}) => Js.t({..})) = ?,
    ~resourceTitleAccessor: option(Js.t({..}) => Js.t({..})) = ?,
    ~getNow: option(Moment.t) = ?,
    ~onNavigate: option(Js.t({..}) => unit) = ?,
    ~onView: option(calendarView => unit) = ?,
    ~onDrillDown: option(unit) = ?,
    ~onRangeChange: option(array(Js.t({..})) => unit) = ?,
    ~onSelectSlot: option(Js.t({..}) => unit) = ?,
    ~onSelectEvent: option(eventItem => unit) = ?,
    ~onDoubleClickEvent: option(eventItem => unit) = ?,
    ~onSelecting: option(range => bool) = ?
  ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=Js.Nullable.({
     /* "localizer": localizer, */
      "elementProps": fromOption(elementProps),
      "date": fromOption(date),
      "view": fromOption(view |> omap(calendarViewToString)),
      "defaultView": fromOption(defaultView |> omap(calendarViewToString)),
      "events": fromOption(events),
      "titleAccessor": fromOption(titleAccessor),
      "tooltipAccessor": fromOption(tooltipAccessor),
      "allDayAccessor": fromOption(allDayAccessor),
      "startAccessor": fromOption(startAccessor),
      "endAccessor": fromOption(endAccessor),
      "resourceAccessor": fromOption(resourceAccessor),
      "resources": fromOption(resources),
      "resourceIdAccessor": fromOption(resourceIdAccessor),
      "resourceTitleAccessor": fromOption(resourceTitleAccessor),
      "getNow": fromOption(getNow),
      /* put others above*/
      "onSelecting": fromOption(onSelecting),
    })
  );
};
