module BigCalendar = {
  [@bs.module]
  external reactClass : ReasonReact.reactClass = "react-big-calendar/lib/index";

  Js.log(reactClass);

  /* Create a localizer */
  [@bs.module]
  external moment : Js.t({..}) = "moment";

  [@bs.module "react-big-calendar/lib/localizers/moment"]
  external localize : Js.t({..}) => Js.t({..}) = "default";
  let localizer = localize(moment);

  Js.log(localizer);

  [@bs.deriving jsConverter]
  type calendarView = [
    | [@bs.as "month"] `Month
    | [@bs.as "week"]  `Week
    | [@bs.as "work_week"] `WorkWeek
    | [@bs.as "day"] `Day
    | [@bs.as "agenda"] `Agenda
  ];

  type eventItem = {.
    "title": string,
    "start": 'a. Js.Nullable.t('a),
    "end_": 'a. Js.Nullable.t('a),
    "allDay": Js.Nullable.t(bool)
    /* TODO: Find a way to implement resource tag */
  };

  let event(~title, ~start = ?, ~end_ = ?, ~allDay = ?, ()) {
    "title": title,
    "start": Js.Nullable.fromOption(start),
    "end_": Js.Nullable.fromOption(end_),
    "allDay": Js.Nullable.fromOption(allDay)
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
    ~resourceTitleAccessor: option(Js.t({..}) => Js.t({..})) = ?
  ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=Js.Nullable.({
     /* "localizer": localizer, */
      "elementProps": fromOption(elementProps),
      "date": fromOption(date),
      "view": fromOption(view),
      "defaultView": fromOption(defaultView),
      "events": fromOption(events),
      "titleAccessor": fromOption(titleAccessor),
      "tooltipAccessor": fromOption(tooltipAccessor),
      "allDayAccessor": fromOption(allDayAccessor),
      "startAccessor": fromOption(startAccessor),
      "endAccessor": fromOption(endAccessor),
      "resourceAccessor": fromOption(resourceAccessor),
      "resources": fromOption(resources),
      "resourceIdAccessor": fromOption(resourceIdAccessor),
      "resourceTitleAccessor": fromOption(resourceTitleAccessor)
    })
  );
};
