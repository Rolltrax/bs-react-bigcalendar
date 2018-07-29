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

  let calendarViewOMap = (cvo) => switch cvo {
    | Some(cv) => Some(calendarViewToString(cv))
    | None => None
  }

  type eventItem = {.
    "title": string,
    "start": Js.Nullable.t(Js.Date.t),
    "end": Js.Nullable.t(Js.Date.t),
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
    "start": Js.Date.t,
    "end": Js.Date.t
  };

  let range(~start, ~end_, ()) {
    "start": start,
    "end": end_
  };

  type propGetter = {.
    "className": string,
  }

  let propGetter(~className, ()) = {
    "className": className
  };
  let make =
  (
    ~elementProps: option(Js.t({..})) = ?,
    ~date: option(Js.Date.t) = ?,
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
    ~resourceIdAccessor: option(string) = ?,
    ~resourceTitleAccessor: option(string) = ?,
    ~getNow: option(Js.Date.t) = ?,
    ~onNavigate: option(Js.Date.t => unit) = ?,
    ~onView: option(calendarView => unit) = ?,
    ~onDrillDown: option('a => unit) = ?,
    ~onRangeChange: option(array(Js.Date.t) => unit) = ?,
    ~onSelectSlot: option(Js.t({..}) => unit) = ?,
    ~onSelectEvent: option(eventItem => unit) = ?,
    ~onDoubleClickEvent: option(eventItem => unit) = ?,
    ~onSelecting: option(range => bool) = ?,
    ~selected: option(eventItem) = ?,
    ~views: option(array(calendarView)) = ?,
    ~drillDownView: option(calendarView) = ?,
    ~getDrillDownView: option((Js.Date.t, calendarView, array(calendarView)) => unit) = ?,
    ~length: option(int) = ?,
    ~toolbar: option(bool) = ?,
    ~popup: option(bool) = ?,
    ~popupOffset: option(Js.t({..})) = ?,
    ~selectable: option(bool) = ?,
    ~resizable: option(bool) = ?,
    ~longPressThreshold: option(int) = ?,
    ~step: option(int) = ?,
    ~timeslots: option(int) = ?,
    ~rtl: option(bool) = ?,
    ~eventPropGetter: option((eventItem) => propGetter) = ?,
    ~slotPropGetter: option(Js.t({. "date": Js.Date.t}) => propGetter) = ?,
    ~showMultiDayTimes: option(bool) = ?,
    ~min: option(Js.Date.t) = ?,
    ~max: option(Js.Date.t) = ?,
    ~scrollToTime: option(Js.Date.t) = ?,
    /* from react-big-calendar: "it's generally better to handle this globally via your i18n library." */
    ~culture: option(string) = ?,
    ~formats: option(Js.t({..})) = ?,
  ) =>
  ReasonReact.wrapJsForReason(
    ~reactClass,
    ~props=Js.Nullable.({
      "localizer": localizer,
      "elementProps": fromOption(elementProps),
      "date": fromOption(date),
      "view": fromOption(calendarViewOMap(view)),
      "defaultView": fromOption(calendarViewOMap(defaultView)),
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
      "onNavigate": fromOption(onNavigate),
      "onView": fromOption(onView),
      "onDrillDown": fromOption(onDrillDown),
      "onRangeChange": fromOption(onRangeChange),
      "onSelectSlot": fromOption(onSelectSlot),
      "onSelectEvent": fromOption(onSelectEvent),
      "onDoubleClickEvent": fromOption(onDoubleClickEvent),
      "onSelecting": fromOption(onSelecting),
      "selected": fromOption(selected),
      "views": fromOption(views),
      "drillDownView": fromOption(drillDownView),
      "getDrillDownView": fromOption(getDrillDownView),
      "length": fromOption(length),
      "toolbar": fromOption(toolbar),
      "popup": fromOption(popup),
      "popupOffset": fromOption(popupOffset),
      "selectable": fromOption(selectable),
      "resizable": fromOption(resizable),
      "longPressThreshold": fromOption(longPressThreshold),
      "step": fromOption(step),
      "timeslots": fromOption(timeslots),
      "rtl": fromOption(rtl),
      "eventPropGetter": fromOption(eventPropGetter),
      "slotPropGetter": fromOption(slotPropGetter),
      "showMultiDayTimes": fromOption(showMultiDayTimes),
      "min": fromOption(min),
      "max": fromOption(max),
      "scrollToTime": fromOption(scrollToTime),
      "culture": fromOption(culture),
      "formats": fromOption(formats),
    })
  );
};
