# app.network.api.HatoClientAPI.Api.Replay — SF6 Steam, TDB 71, 2026-10-19

CFN endpoint group (object.describe on a type-only handle). Every call is `Post<Name>(<Name>In body, Action<<Name>Out> on200, Action<CommonErrorOutput> on500)`.

```
type: app.network.api.HatoClientAPI.Api.Replay : System.Object
fields:
   app.network.WebApiClient Controller
methods:
   System.Void .ctor(app.network.WebApiClient controller)
   System.Void PostDailyTournament(app.network.api.HatoClientAPI.Component.PostReplayDailyTournamentIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostReplayDailyTournamentOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
   System.Void PostDownloadUrl(app.network.api.HatoClientAPI.Component.PostReplayDownloadUrlIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostReplayDownloadUrlOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
   System.Void PostInfo(app.network.api.HatoClientAPI.Component.PostReplayInfoIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostReplayInfoOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
   System.Void PostLocalCheck(app.network.api.HatoClientAPI.Component.PostReplayLocalCheckIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostReplayLocalCheckOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
   System.Void PostMyReplay(app.network.api.HatoClientAPI.Component.PostReplayMyReplayIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostReplayMyReplayOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
   System.Void PostRegister(app.network.api.HatoClientAPI.Component.PostReplayRegisterIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostReplayRegisterOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
   System.Void PostRegisterCancel(app.network.api.HatoClientAPI.Component.PostReplayRegisterCancelIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostReplayRegisterCancelOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
   System.Void PostRegisterList(app.network.api.HatoClientAPI.Component.PostReplayRegisterListIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostReplayRegisterListOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
   System.Void PostSearchDetailed(app.network.api.HatoClientAPI.Component.PostReplaySearchDetailedIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostReplaySearchDetailedOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
   System.Void PostSearchFighterId(app.network.api.HatoClientAPI.Component.PostReplaySearchFighterIdIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostReplaySearchFighterIdOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
   System.Void PostSearchReplayId(app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
   System.Void PostSearchShortId(app.network.api.HatoClientAPI.Component.PostReplaySearchShortIdIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostReplaySearchShortIdOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
   System.Void PostTop(app.network.api.HatoClientAPI.Component.PostReplayTopIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostReplayTopOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
   System.Void PostTopRegister(app.network.api.HatoClientAPI.Component.PostReplayTopRegisterIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostReplayTopRegisterOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
   System.Void PostTopRegisterCancel(app.network.api.HatoClientAPI.Component.PostReplayTopRegisterCancelIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostReplayTopRegisterCancelOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
   System.Void PostTopRegisterCancelOtherVersion(app.network.api.HatoClientAPI.Component.PostReplayTopRegisterCancelOtherVersionIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostReplayTopRegisterCancelOtherVersionOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
   System.Void PostViewsUpdate(app.network.api.HatoClientAPI.Component.PostReplayViewsUpdateIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostReplayViewsUpdateOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
```
