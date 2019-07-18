/* Create a localizer */
[@bs.module]
external moment : Js.t({..}) = "moment";

[@bs.module "react-big-calendar/lib/localizers/moment"]
external localize : Js.t({..}) => Js.t({..}) = "default";
let localizer = localize(moment);

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
};

[@bs.module "react-big-calendar/lib/index"] [@react.component]
external make:
(
  ~elementProps: (Js.t({..})) = ?,
  ~date: (Js.Date.t) = ?,
  ~view: [@bs.string] [
    | `month
    | `week
    | [@bs.as "work_week"] `workWeek
    | `day
    | `agenda
  ] = ?,
  ~defaultView: [@bs.string] [
    | `month
    | `week
    | [@bs.as "work_week"] `workWeek
    | `day
    | `agenda
  ] = ?,
  ~events: (Js.Array.t(eventItem)) = ?,
  ~titleAccessor: (string) = ?,
  ~tooltipAccessor: (string) = ?,
  ~allDayAccessor: (string) = ?,
  ~startAccessor: (string) = ?,
  ~endAccessor: (string) = ?,
  ~resourceAccessor: (string) = ?,
  ~resources: (array(Js.t({..}))) = ?,
  ~resourceIdAccessor: (string) = ?,
  ~resourceTitleAccessor: (string) = ?,
  ~getNow: (Js.Date.t) = ?,
  ~onNavigate: (Js.Date.t => unit) = ?,
  ~onView: (string) => unit = ?,
  ~onDrillDown: ('a => unit) = ?,
  ~onRangeChange: (array(Js.Date.t) => unit) = ?,
  ~onSelectSlot: (Js.t({..}) => unit) = ?,
  ~onSelectEvent: (eventItem => unit) = ?,
  ~onDoubleClickEvent: (eventItem => unit) = ?,
  ~onSelecting: (range => bool) = ?,
  ~selected: (eventItem) = ?,
  ~views: (array(string)) = ?,
  ~drillDownView: (string) = ?,
  ~getDrillDownView: ((Js.Date.t, string, array(string)) => unit) = ?,
  ~length: (int) = ?,
  ~toolbar: (bool) = ?,
  ~popup: (bool) = ?,
  ~popupOffset: (Js.t({..})) = ?,
  ~selectable: (bool) = ?,
  ~resizable: (bool) = ?,
  ~longPressThreshold: (int) = ?,
  ~step: (int) = ?,
  ~timeslots: (int) = ?,
  ~rtl: (bool) = ?,
  ~eventPropGetter: ((eventItem) => propGetter) = ?,
  ~slotPropGetter: (Js.t({. "date": Js.Date.t}) => propGetter) = ?,
  ~showMultiDayTimes: (bool) = ?,
  ~min: (Js.Date.t) = ?,
  ~max: (Js.Date.t) = ?,
  ~scrollToTime: (Js.Date.t) = ?,
  /* from react-big-calendar: "it's generally better to handle this globally via your i18n library." */
  ~culture: (string) = ?,
  ~formats: (Js.t({..})) = ?,
  ~localizer : Js.t({..})
) => React.element =
"Calendar";