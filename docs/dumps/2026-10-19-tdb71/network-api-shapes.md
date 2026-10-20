# Network API describe with request/response shapes (2026-10-19, TDB 71)

Dev page "Describe network API", full chain: NetworkWebApiManager → Hato/RebeWlt/Kpi controls → generated clients → Replay/FightersList/Fighter groups → the In/Out component types for the four endpoints we care about, plus `ReplayingData` and `CommonReplayInfo`.

```
8:14:37 PM · type app.network.api.HatoClientAPI.Component.CommonReplayInfo

app.network.api.HatoClientAPI.Component.CommonReplayInfo : System.Object

fields
System.UInt32 battle_version
System.Boolean is_registered
app.network.api.HatoClientAPI.Component.CommonReplayPlayerInfo player1_info
app.network.api.HatoClientAPI.Component.CommonReplayPlayerInfo player2_info
System.UInt32 replay_battle_sub_type
System.UInt32 replay_battle_type
System.String replay_id
System.Int64 uploaded_at
System.UInt32 views

methods
System.Void .ctor()

8:14:37 PM · type app.BattleReplayDataManager.ReplayingData

app.BattleReplayDataManager.ReplayingData : System.Object

fields
System.String ReplayID
app.BattleReplayData ReplayData
app.network.api.HatoClientAPI.Component.CommonReplayInfo ReplayInfo
System.Boolean IsRivalAi
app.network.api.Enum.ReplayPlaybackClientTab ReplayTab

methods
System.Void .ctor(app.BattleReplayData data, System.String replayID, app.network.api.HatoClientAPI.Component.CommonReplayInfo replayInfo, System.Boolean isRivalAi, app.network.api.Enum.ReplayPlaybackClientTab replayTab)
System.Boolean get_IsLocal()

8:14:37 PM · type app.network.api.HatoClientAPI

not found

8:14:37 PM · type app.network.api.HatoClientAPI.Component.PostFightersListFollowOut

app.network.api.HatoClientAPI.Component.PostFightersListFollowOut : System.Object

fields
app.network.api.HatoClientAPI.Component.CommonFighterBannerInfo followed_fighter_banner_info

methods
System.Void .ctor()

8:14:37 PM · type app.network.api.HatoClientAPI.Component.PostFightersListFollowIn

app.network.api.HatoClientAPI.Component.PostFightersListFollowIn : System.Object

fields
System.UInt32 short_id

methods
System.Void .ctor()

8:14:37 PM · type app.network.api.HatoClientAPI.Component.PostFighterSearchShortIdOut

app.network.api.HatoClientAPI.Component.PostFighterSearchShortIdOut : System.Object

fields
System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonFighterBannerInfo> fighter_banner_list

methods
System.Void .ctor()

8:14:37 PM · type app.network.api.HatoClientAPI.Component.PostFighterSearchShortIdIn

app.network.api.HatoClientAPI.Component.PostFighterSearchShortIdIn : System.Object

fields
System.UInt32 short_id

methods
System.Void .ctor()

8:14:37 PM · type app.network.api.HatoClientAPI.Component.PostReplayDownloadUrlOut

app.network.api.HatoClientAPI.Component.PostReplayDownloadUrlOut : System.Object

fields
System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonReplayDownloadInfo> download_infos

methods
System.Void .ctor()

8:14:37 PM · type app.network.api.HatoClientAPI.Component.PostReplayDownloadUrlIn

app.network.api.HatoClientAPI.Component.PostReplayDownloadUrlIn : System.Object

fields
System.Collections.Generic.List`1<System.String> replay_ids

methods
System.Void .ctor()

8:14:37 PM · type app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdOut

app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdOut : System.Object

fields
System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonReplayInfo> search_result_replay_list

methods
System.Void .ctor()

8:14:36 PM · type app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdIn

app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdIn : System.Object

fields
System.String replay_id
app.network.api.Enum.ReplaySearchIdRoute route

methods
System.Void .ctor()

8:14:36 PM · type app.network.api.HatoClientAPI.Api.Fighter

app.network.api.HatoClientAPI.Api.Fighter : System.Object

fields
app.network.WebApiClient Controller

methods
System.Void .ctor(app.network.WebApiClient controller)
System.Void PostArcadeScoreLatestList(app.network.api.HatoClientAPI.Component.PostFighterArcadeScoreLatestListIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterArcadeScoreLatestListOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostAvatarBattleSettings(app.network.api.HatoClientAPI.Component.PostFighterAvatarBattleSettingsIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterAvatarBattleSettingsOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostAvatarBattleSettingsEdit(app.network.api.HatoClientAPI.Component.PostFighterAvatarBattleSettingsEditIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterAvatarBattleSettingsEditOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostAvatarRandomMatchHistories(app.network.api.HatoClientAPI.Component.PostFighterAvatarRandomMatchHistoriesIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterAvatarRandomMatchHistoriesOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostAvatarRandomMatchSetEquipments(app.network.api.HatoClientAPI.Component.PostFighterAvatarRandomMatchSetEquipmentsIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterAvatarRandomMatchSetEquipmentsOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostAvatarRecipe(app.network.api.HatoClientAPI.Component.PostFighterAvatarRecipeIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterAvatarRecipeOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostAvatarRecipeSlotDelete(app.network.api.HatoClientAPI.Component.PostFighterAvatarRecipeSlotDeleteIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterAvatarRecipeSlotDeleteOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostAvatarRecipeSlotList(app.network.api.HatoClientAPI.Component.PostFighterAvatarRecipeSlotListIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterAvatarRecipeSlotListOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostAvatarRecipeSlotSet(app.network.api.HatoClientAPI.Component.PostFighterAvatarRecipeSlotSetIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterAvatarRecipeSlotSetOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostAvatarRoomGuideInfo(app.network.api.HatoClientAPI.Component.PostFighterAvatarRoomGuideInfoIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterAvatarRoomGuideInfoOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostAvatarSetEdit(app.network.api.HatoClientAPI.Component.PostFighterAvatarSetEditIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterAvatarSetEditOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostAvatarSetEquipments(app.network.api.HatoClientAPI.Component.PostFighterAvatarSetEquipmentsIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterAvatarSetEquipmentsOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostAvatarSetStyle(app.network.api.HatoClientAPI.Component.PostFighterAvatarSetStyleIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterAvatarSetStyleOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostBannerInfo(app.network.api.HatoClientAPI.Component.PostFighterBannerInfoIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterBannerInfoOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostBannerList(app.network.api.HatoClientAPI.Component.PostFighterBannerListIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterBannerListOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostBattleSettings(app.network.api.HatoClientAPI.Component.PostFighterBattleSettingsIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterBattleSettingsOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostBattleSettingsEdit(app.network.api.HatoClientAPI.Component.PostFighterBattleSettingsEditIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterBattleSettingsEditOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostEnjoyCheckFight(app.network.api.HatoClientAPI.Component.PostFighterEnjoyCheckFightIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterEnjoyCheckFightOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostEnjoyCheckReplay(app.network.api.HatoClientAPI.Component.PostFighterEnjoyCheckReplayIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterEnjoyCheckReplayOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostEnjoyCheckReplays(app.network.api.HatoClientAPI.Component.PostFighterEnjoyCheckReplaysIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterEnjoyCheckReplaysOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostEnjoyCheckUser(app.network.api.HatoClientAPI.Component.PostFighterEnjoyCheckUserIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterEnjoyCheckUserOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostEnjoyCheckWatching(app.network.api.HatoClientAPI.Component.PostFighterEnjoyCheckWatchingIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterEnjoyCheckWatchingOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostEnjoyFight(app.network.api.HatoClientAPI.Component.PostFighterEnjoyFightIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterEnjoyFightOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostEnjoyHistoryFight(app.network.api.HatoClientAPI.Component.PostFighterEnjoyHistoryFightIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterEnjoyHistoryFightOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostEnjoyHistoryUser(app.network.api.HatoClientAPI.Component.PostFighterEnjoyHistoryUserIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterEnjoyHistoryUserOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostEnjoyReplay(app.network.api.HatoClientAPI.Component.PostFighterEnjoyReplayIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterEnjoyReplayOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostEnjoyUser(app.network.api.HatoClientAPI.Component.PostFighterEnjoyUserIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterEnjoyUserOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostEnjoyWatching(app.network.api.HatoClientAPI.Component.PostFighterEnjoyWatchingIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterEnjoyWatchingOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostLeaguePoints(app.network.api.HatoClientAPI.Component.PostFighterLeaguePointsIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterLeaguePointsOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostNesysLinkId(app.network.api.HatoClientAPI.Component.PostFighterNesysLinkIdIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterNesysLinkIdOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostOnlinePlayer(app.network.api.HatoClientAPI.Component.PostFighterOnlinePlayerIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterOnlinePlayerOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostOnlineStatusSet(app.network.api.HatoClientAPI.Component.PostFighterOnlineStatusSetIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterOnlineStatusSetOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostProfile(app.network.api.HatoClientAPI.Component.PostFighterProfileIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterProfileOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostProfileBattleLog(app.network.api.HatoClientAPI.Component.PostFighterProfileBattleLogIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterProfileBattleLogOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostProfileParameterSet(app.network.api.HatoClientAPI.Component.PostFighterProfileParameterSetIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterProfileParameterSetOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostProfilePlayHighestLeagueInfo(app.network.api.HatoClientAPI.Component.PostFighterProfilePlayHighestLeagueInfoIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterProfilePlayHighestLeagueInfoOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostProfilePlaySeasonCharacterWinRate(app.network.api.HatoClientAPI.Component.PostFighterProfilePlaySeasonCharacterWinRateIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterProfilePlaySeasonCharacterWinRateOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostProfilePlaySeasonCharacterWinRateByRivalCharacter(app.network.api.HatoClientAPI.Component.PostFighterProfilePlaySeasonCharacterWinRateByRivalCharacterIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterProfilePlaySeasonCharacterWinRateByRivalCharacterOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostProfilePlaySeasonHighestMasterRatingInfo(app.network.api.HatoClientAPI.Component.PostFighterProfilePlaySeasonHighestMasterRatingInfoIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterProfilePlaySeasonHighestMasterRatingInfoOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostProfilePlaySeasonLeagueInfo(app.network.api.HatoClientAPI.Component.PostFighterProfilePlaySeasonLeagueInfoIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterProfilePlaySeasonLeagueInfoOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostProfileLight(app.network.api.HatoClientAPI.Component.PostFighterProfileLightIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterProfileLightOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostRelationship(app.network.api.HatoClientAPI.Component.PostFighterRelationshipIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterRelationshipOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostReport(app.network.api.HatoClientAPI.Component.PostFighterReportIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterReportOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostSearchDetailed(app.network.api.HatoClientAPI.Component.PostFighterSearchDetailedIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterSearchDetailedOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostSearchFighterId(app.network.api.HatoClientAPI.Component.PostFighterSearchFighterIdIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterSearchFighterIdOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostSearchShortId(app.network.api.HatoClientAPI.Component.PostFighterSearchShortIdIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterSearchShortIdOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostSearchSimple(app.network.api.HatoClientAPI.Component.PostFighterSearchSimpleIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterSearchSimpleOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostSettingsCheckAllowCrossPlay(app.network.api.HatoClientAPI.Component.PostFighterSettingsCheckAllowCrossPlayIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterSettingsCheckAllowCrossPlayOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostSettingsPrivacySettings(app.network.api.HatoClientAPI.Component.PostFighterSettingsPrivacySettingsIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterSettingsPrivacySettingsOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostSettingsSetAllowCrossPlay(app.network.api.HatoClientAPI.Component.PostFighterSettingsSetAllowCrossPlayIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterSettingsSetAllowCrossPlayOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostSettingsSetFighterId(app.network.api.HatoClientAPI.Component.PostFighterSettingsSetFighterIdIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterSettingsSetFighterIdOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostSettingsSetHome(app.network.api.HatoClientAPI.Component.PostFighterSettingsSetHomeIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterSettingsSetHomeOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostSettingsSetPrivacySettings(app.network.api.HatoClientAPI.Component.PostFighterSettingsSetPrivacySettingsIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFighterSettingsSetPrivacySettingsOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)

8:14:36 PM · type app.network.api.HatoClientAPI.Api.FightersList

app.network.api.HatoClientAPI.Api.FightersList : System.Object

fields
app.network.WebApiClient Controller

methods
System.Void .ctor(app.network.WebApiClient controller)
System.Void PostBlock(app.network.api.HatoClientAPI.Component.PostFightersListBlockIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListBlockOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostBlockDelete(app.network.api.HatoClientAPI.Component.PostFightersListBlockDeleteIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListBlockDeleteOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostBlockPersonalInfoList(app.network.api.HatoClientAPI.Component.PostFightersListBlockPersonalInfoListIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListBlockPersonalInfoListOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostBlockPlatformRequestCancel(app.network.api.HatoClientAPI.Component.PostFightersListBlockPlatformRequestCancelIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListBlockPlatformRequestCancelOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostBlockSwap(app.network.api.HatoClientAPI.Component.PostFightersListBlockSwapIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListBlockSwapOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostBlockSwapTarget(app.network.api.HatoClientAPI.Component.PostFightersListBlockSwapTargetIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListBlockSwapTargetOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostBlockUpdatePlatformCache(app.network.api.HatoClientAPI.Component.PostFightersListBlockUpdatePlatformCacheIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListBlockUpdatePlatformCacheOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostFollow(app.network.api.HatoClientAPI.Component.PostFightersListFollowIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListFollowOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostFollowDelete(app.network.api.HatoClientAPI.Component.PostFightersListFollowDeleteIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListFollowDeleteOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostFollowList(app.network.api.HatoClientAPI.Component.PostFightersListFollowListIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListFollowListOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostFollowPersonalInfoList(app.network.api.HatoClientAPI.Component.PostFightersListFollowPersonalInfoListIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListFollowPersonalInfoListOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostFriendDelete(app.network.api.HatoClientAPI.Component.PostFightersListFriendDeleteIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListFriendDeleteOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostFriendList(app.network.api.HatoClientAPI.Component.PostFightersListFriendListIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListFriendListOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostFriendPersonalInfoList(app.network.api.HatoClientAPI.Component.PostFightersListFriendPersonalInfoListIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListFriendPersonalInfoListOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostFriendRequestCancel(app.network.api.HatoClientAPI.Component.PostFightersListFriendRequestCancelIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListFriendRequestCancelOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostFriendRequestReject(app.network.api.HatoClientAPI.Component.PostFightersListFriendRequestRejectIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListFriendRequestRejectOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostFriendRequests(app.network.api.HatoClientAPI.Component.PostFightersListFriendRequestsIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListFriendRequestsOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostTop(app.network.api.HatoClientAPI.Component.PostFightersListTopIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListTopOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostTopBlock(app.network.api.HatoClientAPI.Component.PostFightersListTopBlockIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListTopBlockOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostTopBlockDelete(app.network.api.HatoClientAPI.Component.PostFightersListTopBlockDeleteIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListTopBlockDeleteOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostTopBlockSwap(app.network.api.HatoClientAPI.Component.PostFightersListTopBlockSwapIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListTopBlockSwapOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostTopFollow(app.network.api.HatoClientAPI.Component.PostFightersListTopFollowIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListTopFollowOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostTopFollowDelete(app.network.api.HatoClientAPI.Component.PostFightersListTopFollowDeleteIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListTopFollowDeleteOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostTopFriendDelete(app.network.api.HatoClientAPI.Component.PostFightersListTopFriendDeleteIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListTopFriendDeleteOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostTopFriendRequestAccept(app.network.api.HatoClientAPI.Component.PostFightersListTopFriendRequestAcceptIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListTopFriendRequestAcceptOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostTopFriendRequestCancel(app.network.api.HatoClientAPI.Component.PostFightersListTopFriendRequestCancelIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListTopFriendRequestCancelOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostTopFriendRequestReject(app.network.api.HatoClientAPI.Component.PostFightersListTopFriendRequestRejectIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListTopFriendRequestRejectOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)
System.Void PostTopFriendRequests(app.network.api.HatoClientAPI.Component.PostFightersListTopFriendRequestsIn body, System.Action`1<app.network.api.HatoClientAPI.Component.PostFightersListTopFriendRequestsOut> on200, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> on500)

8:14:36 PM · type app.network.api.HatoClientAPI.Api.Replay

app.network.api.HatoClientAPI.Api.Replay : System.Object

fields
app.network.WebApiClient Controller

methods
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

8:14:36 PM · describe app.network.NetworkContextManager

app.network.NetworkContextManager : app.network.NetworkManagerUnit

fields
static System.Boolean IsGroupParameter
app.network.NetworkContextBase <Main>k__BackingField
app.network.RebeContext <Rebe>k__BackingField
System.Collections.Generic.Dictionary`2<System.Int32,app.network.NetworkContextBase> NetworkContextMap

methods
app.network.NetworkContextBase get_Main()
System.Void set_Main(app.network.NetworkContextBase value)
app.network.RebeContext get_Rebe()
System.Void set_Rebe(app.network.RebeContext value)
app.network.NetworkContextBase CreateContext(via.network.ServiceType serviceType)
System.Void Setup()
System.Void Final()
System.Void .ctor()

8:14:36 PM · describe app.network.NetworkSessionManager

app.network.NetworkSessionManager : app.network.NetworkManagerUnit

fields
static System.Boolean IsGroupParameter
app.network.FGBattleSession <FGBattle>k__BackingField
app.network.WTBattleSession <WTBattle>k__BackingField
app.network.InviteSession <Invite>k__BackingField
System.Collections.Generic.Dictionary`2<System.Int32,app.network.NetworkSessionBase> NetworkSessionMap

methods
app.network.FGBattleSession get_FGBattle()
System.Void set_FGBattle(app.network.FGBattleSession value)
app.network.WTBattleSession get_WTBattle()
System.Void set_WTBattle(app.network.WTBattleSession value)
app.network.InviteSession get_Invite()
System.Void set_Invite(app.network.InviteSession value)
app.network.RttChecker GetActiveSessionRtt()
app.network.NetworkSessionBase CreateSession(app.network.PlatformSessionType sessionType)
via.GameObject GetSessionObject(app.network.PlatformSessionType sessionType)
System.Void Setup()
System.Void Final()
System.Void .ctor()

8:14:36 PM · describe app.network.NetworkIdConverterManager

app.network.NetworkIdConverterManager : app.network.NetworkManagerUnit

fields
static System.Boolean IsGroupParameter
via.network.IdConverterBase <IdConverter>k__BackingField
System.Action`3<System.Boolean,System.Collections.Generic.List`1<via.network.Error>,System.Tuple`2[[via.network.utility.Nickname, mscorlib, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null],[via.network.utility.UniqueId, mscorlib, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null]][]> _ConvertUniqueIdsToNicknamePairCompleteCallback
via.network.utility.Request _ConvertUniqueIdsToNicknamePairRequest
System.Collections.Generic.List`1<via.network.Error> _ErrorQue
System.Tuple`2[[via.network.utility.Nickname, mscorlib, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null],[via.network.utility.UniqueId, mscorlib, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null]][] _ConvertQueue

methods
via.network.IdConverterBase get_IdConverter()
System.Void set_IdConverter(via.network.IdConverterBase value)
System.Boolean get_NowConvertUniqueIdsToNicknamePair()
System.Boolean ConvertPlatformServiceUniqueIdsToNicknameUniqueIdPairList(via.network.utility.UniqueIdTbl platUniqueIds, System.Action`3<System.Boolean,System.Collections.Generic.List`1<via.network.Error>,System.Tuple`2[[via.network.utility.Nickname, mscorlib, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null],[via.network.utility.UniqueId, mscorlib, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null]][]> callback)
System.Void RegistDelegate()
System.Void UnregistDelegate()
System.Void ClearConvertUniqueIdsToNicknamePairInfo(System.Boolean invokeCallback)
System.Void Setup()
System.Void Final()
System.Void .ctor()
System.Void <RegistDelegate>b__8_0(via.network.utility.Request req, System.Int32 idx, via.network.utility.UniqueId uniqueId, via.network.utility.Nickname nickname)
System.Void <RegistDelegate>b__8_1(via.network.utility.Request req, via.network.Error err, System.Int32 idx, via.network.utility.UniqueId uniqueId)
System.Void <RegistDelegate>b__8_2(via.network.utility.Request req)

8:14:36 PM · describe app.network.api.HatoClientAPI.HatoClientKPI

app.network.api.HatoClientAPI.HatoClientKPI : System.Object

fields
app.network.api.HatoClientAPI.Api.Outlog <outlog>k__BackingField
app.network.api.HatoClientAPI.Api.OutlogTrial <outlog_trial>k__BackingField

methods
System.Void .ctor(app.network.WebApiClient controller)
app.network.api.HatoClientAPI.Api.Outlog get_outlog()
System.Void set_outlog(app.network.api.HatoClientAPI.Api.Outlog value)
app.network.api.HatoClientAPI.Api.OutlogTrial get_outlog_trial()
System.Void set_outlog_trial(app.network.api.HatoClientAPI.Api.OutlogTrial value)

8:14:36 PM · describe app.network.KpiWebApiControl

app.network.KpiWebApiControl : app.network.WebApiControlBase

fields
app.network.api.HatoClientAPI.HatoClientKPI <Api>k__BackingField
System.Boolean <IsSuppressSend>k__BackingField

methods
app.network.api.HatoClientAPI.HatoClientKPI get_Api()
System.Void set_Api(app.network.api.HatoClientAPI.HatoClientKPI value)
System.Boolean get_ExistsUnsentRequest()
System.Boolean get_IsSuppressSend()
System.Void set_IsSuppressSend(System.Boolean value)
System.Void SetSuppressSend(System.Boolean suppress)
System.Void doSetup()
System.Void .ctor()
System.Boolean <doSetup>b__11_1()

8:14:36 PM · describe app.network.api.RebeClientAPI.RebeWltClientAPI

app.network.api.RebeClientAPI.RebeWltClientAPI : app.network.api.RebeClientAPI.RebeClientAPI

fields


methods
System.Void PostUpdate(app.network.api.RebeClientAPI.Component.PostUpdateIn body, System.Action`1<app.network.api.RebeClientAPI.Component.PostUpdateOut> on200, System.Action`1<app.network.api.RebeClientAPI.Component.CommonErrorOutput> on500)
System.Void GetBalance(app.network.api.RebeClientAPI.Component.GetBalanceIn body, System.Action`1<app.network.api.RebeClientAPI.Component.GetBalanceOut> on200, System.Action`1<app.network.api.RebeClientAPI.Component.CommonErrorOutput> on500)
System.Void GetSteamProducts(app.network.api.RebeClientAPI.Component.GetSteamProductsIn body, System.Action`1<app.network.api.RebeClientAPI.Component.GetSteamProductsOut> on200, System.Action`1<app.network.api.RebeClientAPI.Component.CommonErrorOutput> on500)
System.Void PostSteamInitialize(app.network.api.RebeClientAPI.Component.PostSteamInitializeIn body, System.Action`1<app.network.api.RebeClientAPI.Component.PostSteamInitializeOut> on200, System.Action`1<app.network.api.RebeClientAPI.Component.CommonErrorOutput> on500)
System.Void PostSteamFinalize(app.network.api.RebeClientAPI.Component.PostSteamFinalizeIn body, System.Action`1<app.network.api.RebeClientAPI.Component.PostSteamFinalizeOut> on200, System.Action`1<app.network.api.RebeClientAPI.Component.CommonErrorOutput> on500)
System.Void .ctor()

8:14:36 PM · describe app.network.RebeWltWebApiControl

app.network.RebeWltWebApiControl : app.network.RebeWebApiControl`1<app.network.api.RebeClientAPI.RebeWltClientAPI>

fields


methods
System.Void .ctor()

8:14:36 PM · describe app.network.api.HatoClientAPI.HatoClientAPI

app.network.api.HatoClientAPI.HatoClientAPI : System.Object

fields
app.network.api.HatoClientAPI.Api.Auth <auth>k__BackingField
app.network.api.HatoClientAPI.Api.Chat <chat>k__BackingField
app.network.api.HatoClientAPI.Api.Circle <circle>k__BackingField
app.network.api.HatoClientAPI.Api.Debug <debug>k__BackingField
app.network.api.HatoClientAPI.Api.Fighter <fighter>k__BackingField
app.network.api.HatoClientAPI.Api.FightersList <fighters_list>k__BackingField
app.network.api.HatoClientAPI.Api.Inventory <inventory>k__BackingField
app.network.api.HatoClientAPI.Api.Mail <mail>k__BackingField
app.network.api.HatoClientAPI.Api.Mame <mame>k__BackingField
app.network.api.HatoClientAPI.Api.Matching <matching>k__BackingField
app.network.api.HatoClientAPI.Api.ModeSelect <mode_select>k__BackingField
app.network.api.HatoClientAPI.Api.MultiMenu <multi_menu>k__BackingField
app.network.api.HatoClientAPI.Api.Ogym <ogym>k__BackingField
app.network.api.HatoClientAPI.Api.Ranking <ranking>k__BackingField
app.network.api.HatoClientAPI.Api.Replay <replay>k__BackingField
app.network.api.HatoClientAPI.Api.Rewards <rewards>k__BackingField
app.network.api.HatoClientAPI.Api.RivalAi <rival_ai>k__BackingField
app.network.api.HatoClientAPI.Api.Shop <shop>k__BackingField
app.network.api.HatoClientAPI.Api.Sys <sys>k__BackingField

methods
System.Void .ctor(app.network.WebApiClient controller)
app.network.api.HatoClientAPI.Api.Auth get_auth()
System.Void set_auth(app.network.api.HatoClientAPI.Api.Auth value)
app.network.api.HatoClientAPI.Api.Chat get_chat()
System.Void set_chat(app.network.api.HatoClientAPI.Api.Chat value)
app.network.api.HatoClientAPI.Api.Circle get_circle()
System.Void set_circle(app.network.api.HatoClientAPI.Api.Circle value)
app.network.api.HatoClientAPI.Api.Debug get_debug()
System.Void set_debug(app.network.api.HatoClientAPI.Api.Debug value)
app.network.api.HatoClientAPI.Api.Fighter get_fighter()
System.Void set_fighter(app.network.api.HatoClientAPI.Api.Fighter value)
app.network.api.HatoClientAPI.Api.FightersList get_fighters_list()
System.Void set_fighters_list(app.network.api.HatoClientAPI.Api.FightersList value)
app.network.api.HatoClientAPI.Api.Inventory get_inventory()
System.Void set_inventory(app.network.api.HatoClientAPI.Api.Inventory value)
app.network.api.HatoClientAPI.Api.Mail get_mail()
System.Void set_mail(app.network.api.HatoClientAPI.Api.Mail value)
app.network.api.HatoClientAPI.Api.Mame get_mame()
System.Void set_mame(app.network.api.HatoClientAPI.Api.Mame value)
app.network.api.HatoClientAPI.Api.Matching get_matching()
System.Void set_matching(app.network.api.HatoClientAPI.Api.Matching value)
app.network.api.HatoClientAPI.Api.ModeSelect get_mode_select()
System.Void set_mode_select(app.network.api.HatoClientAPI.Api.ModeSelect value)
app.network.api.HatoClientAPI.Api.MultiMenu get_multi_menu()
System.Void set_multi_menu(app.network.api.HatoClientAPI.Api.MultiMenu value)
app.network.api.HatoClientAPI.Api.Ogym get_ogym()
System.Void set_ogym(app.network.api.HatoClientAPI.Api.Ogym value)
app.network.api.HatoClientAPI.Api.Ranking get_ranking()
System.Void set_ranking(app.network.api.HatoClientAPI.Api.Ranking value)
app.network.api.HatoClientAPI.Api.Replay get_replay()
System.Void set_replay(app.network.api.HatoClientAPI.Api.Replay value)
app.network.api.HatoClientAPI.Api.Rewards get_rewards()
System.Void set_rewards(app.network.api.HatoClientAPI.Api.Rewards value)
app.network.api.HatoClientAPI.Api.RivalAi get_rival_ai()
System.Void set_rival_ai(app.network.api.HatoClientAPI.Api.RivalAi value)
app.network.api.HatoClientAPI.Api.Shop get_shop()
System.Void set_shop(app.network.api.HatoClientAPI.Api.Shop value)
app.network.api.HatoClientAPI.Api.Sys get_sys()
System.Void set_sys(app.network.api.HatoClientAPI.Api.Sys value)

8:14:36 PM · describe app.network.HatoWebApiControl

app.network.HatoWebApiControl : app.network.WebApiControlBase

fields
static System.UInt32 NewChallengerRank
static System.Single UpdateLeagueParamWaitTime
app.network.api.HatoClientAPI.HatoClientAPI <Api>k__BackingField
System.UInt32 <ShortId>k__BackingField
System.UInt32 <MannerGrade>k__BackingField
app.network.api.HatoClientAPI.Component.CommonFighterBannerInfo <BannerInfo>k__BackingField
app.network.api.HatoClientAPI.Component.CommonMatchingExamState <ExamState>k__BackingField
System.Boolean <IsMasterLeagueEnabled>k__BackingField
System.Boolean <IsForceCrossPlayOff>k__BackingField
System.String SignedURL
System.Int64 MonthlyAvatarPointOld
System.Int64 MonthlyAvatarPoint
System.Boolean MonthlyAvatarPointReset
System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonMatchingLeaguePoint> LeagueParamList
System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonRivalAiCharacterLeagueRank> LifenLeagueParamList
System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonAuthLoginInfo.ConsecutiveWinsVal> ConsecutiveWinList
System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonAuthWarningMessage> WarningMessageList
System.Single UpdateLeagueParamWaitTimeWork

methods
app.network.api.HatoClientAPI.HatoClientAPI get_Api()
System.Void set_Api(app.network.api.HatoClientAPI.HatoClientAPI value)
System.UInt32 get_ShortId()
System.Void set_ShortId(System.UInt32 value)
System.UInt32 get_MannerGrade()
System.Void set_MannerGrade(System.UInt32 value)
app.network.api.HatoClientAPI.Component.CommonFighterBannerInfo get_BannerInfo()
System.Void set_BannerInfo(app.network.api.HatoClientAPI.Component.CommonFighterBannerInfo value)
app.network.api.HatoClientAPI.Component.CommonMatchingExamState get_ExamState()
System.Void set_ExamState(app.network.api.HatoClientAPI.Component.CommonMatchingExamState value)
System.Boolean get_IsMasterLeagueEnabled()
System.Void set_IsMasterLeagueEnabled(System.Boolean value)
System.Boolean get_IsForceCrossPlayOff()
System.Void set_IsForceCrossPlayOff(System.Boolean value)
System.Void SetShortId(System.UInt32 shortId)
System.Void SetMannerGrade(System.UInt32 mannerGrade)
System.Void SetBannerInfo(app.network.api.HatoClientAPI.Component.CommonFighterBannerInfo bannerInfo)
app.network.api.Enum.PlatformId GetPlatformId()
System.String GetMainCircleName()
app.network.api.HatoClientAPI.Component.CommonCircleEmblem GetMainCircleEmblem()
System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonAuthWarningMessage> GetWarningMessageList()
System.UInt32 GetMainCircleLeaderShortId()
System.Void ReqeustUpdateLeagueParam(System.Action callback)
System.Void SetLeagueParamList(System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonMatchingLeaguePoint> leagueParamList)
app.network.api.HatoClientAPI.Component.CommonMatchingLeaguePoint GetLeagueParam(System.Int32 fighterId)
System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonMatchingLeaguePoint> GetLeagueParamListCopy()
System.UInt32 GetLeagueRank(System.Int32 fighterId)
System.Int32 GetLeaguePoint(System.Int32 fighterId)
System.Void SetLifenLeagueParamList(System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonRivalAiCharacterLeagueRank> leagueParamList)
System.Void SetLifenLeagueParam(app.network.api.HatoClientAPI.Component.CommonRivalAiCharacterLeagueRank leagueParam)
app.network.api.HatoClientAPI.Component.CommonRivalAiCharacterLeagueRank GetLifenLeagueParam(System.Int32 fighterId)
System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonRivalAiCharacterLeagueRank> GetLifenLeagueParamListCopy()
System.UInt32 GetLifenLeagueRank(System.Int32 fighterId)
System.Void SetConsecutiveWins(System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonAuthLoginInfo.ConsecutiveWinsVal> list)
System.Void SetWarningMessageList(System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonAuthWarningMessage> list)
System.Void SetConsecutiveWins(System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.PostMatchingFightEndOut.ConsecutiveWinsVal> list)
System.Void SetConsecutiveWins(System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.PostMatchingEndCpuExamOut.ConsecutiveWinsVal> list)
System.UInt32 GetConsecutiveWin(app.network.api.Enum.MatchingType matchingType, System.UInt32 fighterId)
System.Boolean IsDecideExamRank()
app.network.api.HatoClientAPI.Component.CommonMatchingExamInfo GetFighterExamInfo(System.Int32 fighterId)
System.Boolean IsNeedExamMatch(System.Int32 fighterId)
System.Boolean IsNowExamMatch(System.Int32 fighterId)
System.Boolean IsExamCpuBattle(System.Int32 fighterId)
System.Void SetExamState(app.network.api.HatoClientAPI.Component.CommonMatchingExamState examState)
System.Void SetFirstExamState(System.Int32 fighterId)
System.Void SetExamRank(app.network.api.Enum.MatchingExamRank selectRank)
System.Void SetMasterLeagueEnabled(System.Boolean enabled)
System.Void SetForceCrossPlayOffFlag(System.Boolean flag)
System.Void SetSignedURL(System.String url)
System.Void SetAvatarRandomMatchPoint(System.Int64 point, System.Boolean isReset)
System.Void doSetup()
System.Void update()
System.Void .ctor()

8:14:36 PM · describe app.network.NetworkWebApiManager

app.network.NetworkWebApiManager : app.network.NetworkManagerUnit

fields
static System.Boolean IsGroupParameter
app.network.HatoWebApiControl <Hato>k__BackingField
app.network.RebeWltWebApiControl <RebeWlt>k__BackingField
app.network.KpiWebApiControl <Kpi>k__BackingField
System.Collections.Generic.Dictionary`2<System.Int32,app.network.WebApiControlBase> WebApiMap

methods
app.network.HatoWebApiControl get_Hato()
System.Void set_Hato(app.network.HatoWebApiControl value)
app.network.RebeWltWebApiControl get_RebeWlt()
System.Void set_RebeWlt(app.network.RebeWltWebApiControl value)
app.network.KpiWebApiControl get_Kpi()
System.Void set_Kpi(app.network.KpiWebApiControl value)
app.network.WebApiControlBase CreateWebApi(app.network.WebApiType webApiType)
via.GameObject CreateWebApiObject()
System.Void Setup()
System.Void Final()
System.Void .ctor()```
