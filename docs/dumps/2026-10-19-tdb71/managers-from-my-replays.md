# Managers described from: My Replays list — SF6 Steam, TDB 71, 2026-10-19

Output of the dev page's "Describe managers".

```
describe app.esports.timeline.BattleTimelineManager2nd

singleton not found

describe app.esports.BattleTimeLineManager

app.esports.BattleTimeLineManager : app.SingletonBaseBehavior`1<app.esports.BattleTimeLineManager>

fields
app.BattleTimeLineOverwriteData OverwriteResource
System.Boolean <IsReqAllUnBind>k__BackingField
System.Boolean IsExistCameraValue
System.Action <BindEvent>k__BackingField
System.Action <UnBindEvent>k__BackingField
static System.String INSTANCE_PATH
static System.String MASK_LIGHT_NAME
static System.String SKYDOME_NAME
System.Single _CameraBlendValue
System.Single _BeforeCameraBlendValue
System.Single _SpecificValueBlend
System.Single _BeforeSpecificValueBlend
System.Single _ImageQualityDown
System.Single _BeforeImageQualityDown
System.Boolean _IsSetter
System.Single _LightBlendValue
System.Single _BeforeLightBlendValue
System.Boolean _IsEnvBlend_FG
System.Boolean _IsBeforeEnvBlend
System.Func`1<System.Boolean> _IsEnvBlend
System.Func`1<System.Boolean> _IsCheckEnvBlend
System.Boolean _IsBeforeNoDrawSAGround_WT
System.Boolean _IsInit
System.Boolean _IsSetuped
app.esports.PlayerBehaviorManager _PBManager
app.btlCameraBlend _CameraBlend
via.render.RenderOutput _BcRenderOutput
app.PlayerBehavior[] _PlayerBehaviors
System.Collections.Generic.List`1<app.esports.BattleTimeLineManager.TempLight`1<via.render.Light>> _LightComps
System.Collections.Generic.List`1<app.esports.BattleTimeLineManager.TempLight`1<via.render.DirectionalLight>> _LightDirectionalComps
System.Collections.Generic.List`1<app.esports.BattleTimeLineManager.TempLight`1<app.LightMapController>> _LightMapComps
System.Collections.Generic.List`1<app.esports.BattleTimeLineManager.TempLight`1<via.render.Light>> _LightFollowComps
System.Collections.Generic.List`1<app.esports.BattleTimeLineManager.TempLightProbes`1<via.render.LightProbes>> _LightProbesComps
System.Collections.Generic.List`1<app.esports.BattleTimeLineManager.TempEnvComponent`1<via.render.VolumetricFog>> _VolumetricFogComps
via.render.VolumetricFogControl _VolumetricFogControl
System.Collections.Generic.List`1<app.esports.BattleTimeLineManager.TempLight`1<via.render.IBL>> _IblComps
via.effect.script.EnvironmentEffectManager[] _EnvironmentEffectManagers
System.Collections.Generic.List`1<app.esports.BattleTimeLineManager.BlendCloudScape> _CloudScapes
System.Collections.Generic.List`1<app.esports.BattleTimeLineManager.TempEnvComponent`1<via.landscape.Foliage>> _FoliageEnvs
System.Collections.Generic.List`1<app.esports.BattleTimeLineManager.SkydomeMeshLight> _SkydomeMeshLights
System.Collections.Generic.List`1<via.relib.light.ReLibLightBehaviorBase> _ReLibLightBehaviors
System.Int32 _SpeedTreeLodBias
app.owGlobalParam.GlobalParamData[] _GlobalParamInitValues
System.Collections.Generic.Dictionary`2<System.Int32,app.esports.BattleTimeLineManager.VariablesHubata> _VariablesHubDict
via.GameObject _WTMSAGround
via.render.CustomFilterBeforeTransparent _CustomFilterBT
System.Collections.Generic.Dictionary`2<System.Int32,via.render.MeshMaterialResourceHolder> _CustomFilterDataDict
System.Collections.Generic.List`1<app.esports.BattleTimeLineMaterialController> _MatParamController
System.Collections.Generic.List`1<app.CharacterLightBehavior> _LightBehaviors
System.Collections.Generic.List`1<app.CharacterLightController> _LightControllers
System.Collections.Generic.List`1<app.LightPriorityController> _LightPriorityControllers
System.Collections.Generic.Dictionary`2<System.Int32,System.Collections.Generic.List`1<app.esports.BattleTimeLineManager.MeshData>> _MeshDataDict
System.Collections.Generic.List`1<app.esports.BattleTimeLineManager.OccluderData> _Occluders
System.Func`1<System.Boolean> _UpdateBattleSetting
System.Single _DefaultImageQuality
System.Boolean _IsPrevSlowWorld
System.Boolean _IsBinding
via.render.RenderConfig.Quality _LightQuality
via.render.RenderConfig.Quality _ShaderQuality
System.Action _OnLateUpdateEvent
System.ValueTuple`2[[System.Int32, mscorlib, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null],[System.Action, mscorlib, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null]][] _OnUpdateEventArray
app.battle.uBattleCore _BattleCore
System.Boolean _IsAlreadyAutoForward
System.Boolean _IsForwardNow
System.UInt32 _SkydomeHash
System.UInt32 _EmissiveIntHash
System.Boolean _IsDestroyManager2nd
via.threading.SimpleReaderWriterLock _AllUnbindLock
System.Boolean _IsEnvBlend_WT
System.Boolean _IsNoDrawSAGround_WT
System.Boolean _IsFieldSA3Mask_now
System.Boolean _IsFieldSA3Mask_old
System.Collections.Generic.HashSet`1<via.GameObject> _Mod_Objects

methods
System.Single get_CameraBlendValue()
System.Void set_CameraBlendValue(System.Single value)
System.Single get_LightBlendValue()
System.Void set_LightBlendValue(System.Single value)
System.Boolean get_IsEnvBlend()
System.Void set_IsEnvBlend(System.Boolean value)
System.Single get_SpecificValueBlend()
System.Void set_SpecificValueBlend(System.Single value)
System.Single get_ImageQualityDown()
System.Void set_ImageQualityDown(System.Single value)
System.Boolean get_IsBinding()
System.Boolean get_IsReqAllUnBind()
System.Void set_IsReqAllUnBind(System.Boolean value)
System.Void SetReqAllBind(System.Boolean isReq)
System.Action get_BindEvent()
System.Void set_BindEvent(System.Action value)
System.Action get_UnBindEvent()
System.Void set_UnBindEvent(System.Action value)
System.Void doStart()
System.Void doUpdate()
System.Void doLateUpdate()
System.Void SetBattleCore(app.battle.uBattleCore battleCore)
System.Void StartBattle(System.Boolean isAlready)
System.Void RegistLightBehavior(app.CharacterLightBehavior behavior)
System.Void UnregistLightBehavior(app.CharacterLightBehavior behavior)
System.Void RegistLightController(app.CharacterLightController behavior)
System.Void UnregistLightController(app.CharacterLightController behavior)
System.Void SetInitialValue()
System.Void ReloadInitialValue()
System.Void ReloadInitialValue_Light()
System.Void ReloadInitialValue_LightPriority()
System.Void Release()
System.Void ResetValue()
System.Void ResetCameraValue()
System.Void SetupTimeline()
System.Void SetupTimeline(app.PlayerBehavior pb)
System.Boolean RegisterSetPropertyDelegateClass(System.Type type)
System.Void ManualUpdate()
System.Void SetUpdateEvent(System.Int32 plId, System.Action action, System.Int32 priority)
System.Boolean Initialize()
System.Void TimeLineUpdate()
System.Boolean CantTimeLineUpdate()
System.Void CheckBattleSetting()
System.Boolean IsCheckLightBlend(System.Boolean isUp)
System.Boolean IsCheckEnvBlend_FG()
System.Boolean IsCheckCameraBlend()
System.Boolean IsCheckOverwriteBlend()
System.Void CameraBlend(System.Single val)
System.Void OverwriteBlend()
System.Void EnvBlend()
System.Void LightBlend(System.Single value, System.Boolean isUp)
System.Void DirectionalLightOFF()
System.Void DirectionalLightON()
System.Void FollowLightOFF()
System.Void FollowLightON()
System.Void SetFighter(app.PlayerBehavior pb)
System.Void SetLight()
System.Void SetEnv()
System.Void SetCameraLastValue()
System.Void CloudScapeCheck()
System.Void SetBattlePause(System.Boolean isPause)
System.Void setAutoUpdateInput(System.Boolean isInput)
System.Void lateUpdate_AutoUpdateInput()
System.Void ResetLod()
System.Void SetNextLod(System.Int32 playerID)
System.Void SetPrevLod()
System.Void AllUnBindAction()
System.Void ImageQualityBlend()
System.Boolean GetEnvBlend_FG()
System.Void CheckUpdateEvent()
System.Void OnBind()
System.Void OnUnBind()
System.Void OnPreUpdate()
System.Void OnLateUpdate()
System.Void UpdateLightPriority()
System.Boolean isClipType(app.esports.BattleTimeLineManager.EClipType saType)
System.Boolean get_IsAllSetuped()
System.Boolean get_IsNotRollFowardEffect()
System.Void Trace(System.Object data, System.Int32 traceType, System.Boolean isNoAdd, System.String mName, System.String pName)
System.Boolean get_IsEnvBlend_WT()
System.Void set_IsEnvBlend_WT(System.Boolean value)
System.Boolean get_IsNoDrawSAGround_WT()
System.Void set_IsNoDrawSAGround_WT(System.Boolean value)
System.Void SetupSAGround(via.GameObject obj)
System.Void wt_doUpdate()
System.Void wt_init()
System.Boolean isCheckEnvBlend_WT()
System.Boolean getEnvBlend_WT()
System.Void forceUpdateEnv()
System.Void updateWorldTourEnvBlend(System.Boolean flag)
System.Void updateBHAvatarBattleEnvBlend(System.Boolean flag)
System.Boolean isWTBattle()
System.String[] getFGStagePath()
System.Void updateWorldTourSectionEnvBlend(System.Int32 cityId, app.worldtour.WTPathDefine.SectionType sectionType, app.worldtour.WTDefine.TimeType timeType, System.Boolean flag, System.Boolean mode_ex, System.Boolean time_only)
System.Void setRenderOutputID(via.GameObject go, System.Boolean flag, via.render.RenderOutputID outputID)
System.Int32 isOnRenderOutputID(via.GameObject go, via.render.RenderOutputID outputID)
System.Void setupWorldTourModObjects()
System.Void resetWorldTourModObjects()
System.Void setStageBattleSA3_in(via.GameObject go, System.Boolean flag)
System.Void setStageBattleSA3(via.Folder stage_fold, System.Boolean flag)
System.Void onBind_Wt()
System.Void onUnbind_Wt()
System.Void .ctor()
System.Boolean <CheckBattleSetting>b__56_0()
System.Void <setupWorldTourModObjects>g__setupWorldTourSectionEnv|186_2(app.worldtour.WTPathDefine.SectionType sectionType, app.esports.BattleTimeLineManager.<>c__DisplayClass186_0 )
System.Void <setupWorldTourModObjects>g__setupTargetMesh|186_0(via.Folder stage_fold)
System.Void <setupWorldTourModObjects>g__setupTargetMeshMain|186_1(via.GameObject go)

describe app.network.NetworkManager

app.network.NetworkManager : app.SingletonBaseBehavior`1<app.network.NetworkManager>

fields
static System.Boolean IsGroupParameter
System.Boolean <IsValid>k__BackingField
via.network.ServiceType <ServiceType>k__BackingField
static System.Boolean _gs_Network
via.network.core.InterfaceType ConnectionType
System.Collections.Generic.List`1<via.network.core.InterfaceInfo> InterfaceInfo
app.network.NetworkContextManager <Context>k__BackingField
app.network.NetworkUtilityManager <Utility>k__BackingField
app.network.NetworkIdConverterManager <IdConverter>k__BackingField
app.network.NetworkChargeManager <Charge>k__BackingField
app.network.NetworkPrivilegeManager <Privilege>k__BackingField
app.network.NetworkWebApiManager <WebApi>k__BackingField
app.network.NetworkSessionManager <Session>k__BackingField
app.network.NetworkServerManager <Server>k__BackingField
app.network.NetworkFileManager <File>k__BackingField
app.network.NetworkSpeedTestManager <SpeedTest>k__BackingField
app.network.NetworkAchievementManager <Achievement>k__BackingField
System.String <ApiServerAddr>k__BackingField
System.String <NotifyServerAddr>k__BackingField
System.String <NotifyServerPath>k__BackingField
System.String _BattleHubServerAddr
System.String _BattleHubServerPath
System.String _CustomRoomServerAddr
System.String _CustomRoomServerPath
System.String <PatchServerAddr>k__BackingField
static System.Boolean IsGroupResource
app.network.udNetworkManagerSettingUserData Setting
System.Collections.Generic.Dictionary`2<System.String,via.GameObject> ManagerObjectDic
System.Collections.Generic.List`1<app.network.NetworkManagerUnit> ManagerUnitList

methods
System.Boolean get_IsValid()
System.Void set_IsValid(System.Boolean value)
via.network.ServiceType get_ServiceType()
System.Void set_ServiceType(via.network.ServiceType value)
via.network.core.InterfaceType GetNetworkConnectionInfo()
app.network.NetworkContextManager get_Context()
System.Void set_Context(app.network.NetworkContextManager value)
app.network.NetworkUtilityManager get_Utility()
System.Void set_Utility(app.network.NetworkUtilityManager value)
app.network.NetworkIdConverterManager get_IdConverter()
System.Void set_IdConverter(app.network.NetworkIdConverterManager value)
app.network.NetworkChargeManager get_Charge()
System.Void set_Charge(app.network.NetworkChargeManager value)
app.network.NetworkPrivilegeManager get_Privilege()
System.Void set_Privilege(app.network.NetworkPrivilegeManager value)
app.network.NetworkWebApiManager get_WebApi()
System.Void set_WebApi(app.network.NetworkWebApiManager value)
app.network.NetworkSessionManager get_Session()
System.Void set_Session(app.network.NetworkSessionManager value)
app.network.NetworkServerManager get_Server()
System.Void set_Server(app.network.NetworkServerManager value)
app.network.NetworkFileManager get_File()
System.Void set_File(app.network.NetworkFileManager value)
app.network.NetworkSpeedTestManager get_SpeedTest()
System.Void set_SpeedTest(app.network.NetworkSpeedTestManager value)
app.network.NetworkAchievementManager get_Achievement()
System.Void set_Achievement(app.network.NetworkAchievementManager value)
System.String get_ApiServerAddr()
System.Void set_ApiServerAddr(System.String value)
System.String get_NotifyServerAddr()
System.Void set_NotifyServerAddr(System.String value)
System.String get_NotifyServerPath()
System.Void set_NotifyServerPath(System.String value)
System.String get_BattleHubServerAddr()
System.Void set_BattleHubServerAddr(System.String value)
System.String get_BattleHubServerPath()
System.Void set_BattleHubServerPath(System.String value)
System.String get_CustomRoomServerAddr()
System.Void set_CustomRoomServerAddr(System.String value)
System.String get_CustomRoomServerPath()
System.Void set_CustomRoomServerPath(System.String value)
System.String get_PatchServerAddr()
System.Void set_PatchServerAddr(System.String value)
via.GameObject GetManagerObject(System.String path)
System.Void CollectManagerObject(System.String path, via.GameObject parent)
via.network.ServiceType CheckServiceType()
System.Void PreInitialize()
System.Void doStart()
System.Void doUpdate()
System.Void doOnDestroy()
System.Void .ctor()

describe app.global.FighterProfileManager

app.global.FighterProfileManager : app.SingletonBaseBehavior`1<app.global.FighterProfileManager>

fields
static System.Single StreamingWaitTime
static System.Boolean GroupSeparator_Setting
app.global.FighterProfileManager.UdSpecialPoseCameraSetting SpecialPoseCameraSettingUd
via.render.RenderTargetTextureResourceHolder RTTResource
System.Boolean <IsBattleScene>k__BackingField
app.worldtour.CaptureRoomController CaptureRoomController
app.worldtour.CaptureRoomFighterProfileParam CaptureRoomParam
System.Collections.Generic.List`1<app.global.FighterProfileManager.InternalRequestData> RequestDataList
app.global.FighterProfileManager.InternalRequestData CurrentProcessingData
System.Boolean IsActive

methods
System.Boolean get_IsBattleScene()
System.Void set_IsBattleScene(System.Boolean value)
System.Void RequestSetFighterProfileTexture(app.global.FighterProfileManager.RequestData data, app.global.FighterProfileManager.CallBackFunc callBack, System.Int32 arg)
System.Void RequestSetFighterProfileTexture(app.global.FighterProfileManager.NetRequestData data, app.global.FighterProfileManager.CallBackFunc callBack, System.Int32 arg)
System.Void RequestSetFighterProfileTexture(app.global.FighterProfileManager.NewChallengerRequestData data, app.global.FighterProfileManager.CallBackFunc callBack, System.Int32 arg)
System.Void DeactivateFighterProfileCapture(System.Boolean isBattle)
System.Void ActivateFighterProfileCapture(System.Boolean isBattle)
System.Void ActivateFighterProfileCaptureRoom()
System.Void DeactivateFighterProfileCaptureRoom()
System.Void OnLoadCaptureRoom(System.Collections.Generic.List`1<app.worldtour.CaptureRoomController> controllers)
System.Void OnAvatarModelChange(app.worldtour.WTLoadBehavior behavior)
System.Void OnDefaultEquipSet(app.worldtour.WTLoadBehavior behavior)
System.Void doStart()
System.Void doOnDestroy()
System.Void doUpdate()
System.Void doLateUpdate()
System.Void .ctor()
static System.Void .cctor()
System.Boolean <OnAvatarModelChange>b__32_0(app.global.FighterProfileManager.UdFighterProfileCameraSetting.RenderInfoSetting x)
System.Boolean <doLateUpdate>b__37_0(app.global.FighterProfileManager.UdFighterProfileCameraSetting.RenderInfoSetting x)

describe app.FighterProfileSyncManager

app.FighterProfileSyncManager : app.SingletonBaseBehavior`1<app.FighterProfileSyncManager>

fields
app.FighterProfileSyncManager.RequestStatus Status
System.Single IntervaTime
System.Single IntervalElapsedTime
System.Single DelayTime
System.Single DelayElapsedTime
via.threading.SimpleReaderWriterLock Lock
app.FighterProfileSyncManager.RequestData CurrentRequest
app.FighterProfileSyncManager.RequestData ReservedRequest

methods
System.Boolean get_Available()
System.Int32 get_CurrentRequestCount()
System.Int32 get_ReservedRequestCount()
System.Void RequestUpdateFighterProfile(System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> callback)
System.Void RequestUpdateAvaterEdit(System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> callback)
System.Void RequestUpdateAvaterStatus(System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> callback)
System.Void SendFighterProfile(app.network.api.HatoClientAPI.Component.PostFighterProfileParameterSetIn data, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> callback)
System.Void SendAvaterEdit(app.network.api.HatoClientAPI.Component.PostFighterAvatarSetEditIn data, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> callback)
System.Void SendAvaterStatus(app.network.api.HatoClientAPI.Component.PostFighterAvatarSetEquipmentsIn data, System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput> callback)
System.Void OnChangeGameMode(app.INotify n)
System.Void doStart()
System.Void doLateUpdate()
System.Void .ctor()
System.Void <doLateUpdate>b__24_0(app.network.api.HatoClientAPI.Component.CommonErrorOutput error)

describe app.InviteManager

app.InviteManager : app.SingletonBaseBehavior`1<app.InviteManager>

fields
static System.Boolean IsGroupParameter
System.Boolean <IsValid>k__BackingField
System.Boolean <IsInviting>k__BackingField
System.Boolean <IsExtanalInvite>k__BackingField
System.Boolean <IsTryLogin>k__BackingField
static System.Boolean IsGroupResource
app.udInviteManagerSettingUserData Setting
app.InviteManager.ExternalInviteSessionParam RequestExternalSessionParam
app.InviteManager.ExternalInviteSessionParam ExternalSessionParam

methods
System.Boolean get_IsValid()
System.Void set_IsValid(System.Boolean value)
System.Boolean get_IsInviting()
System.Void set_IsInviting(System.Boolean value)
System.Boolean get_IsJoinSession()
System.Boolean get_IsExtanalInvite()
System.Void set_IsExtanalInvite(System.Boolean value)
System.Boolean get_IsTryLogin()
System.Void set_IsTryLogin(System.Boolean value)
System.Boolean RequestCreateSession(System.UInt32 memberMax, app.network.api.Enum.InviteCategory inviteType, System.String sessionKey, System.Action`1<app.network.NetworkResult> callback)
System.Boolean RequestJoinSession(System.Action`1<app.network.NetworkResult> callback)
System.Boolean RequestJoinSession(System.String sessionId, System.Action`1<app.network.NetworkResult> callback)
System.Boolean RequestInvite(System.Action`1<app.network.NetworkResult> callback)
System.Boolean RequestInvite(via.network.utility.UniqueIdTbl uniqueIdTbl, System.Action`1<app.network.NetworkResult> callback)
System.Void RequestLeaveSession()
System.Void RequesExternalInvite(app.network.api.Enum.InviteCategory inviteType, System.String sessionKey, app.network.api.Enum.InvitedType type)
System.Void FinishInviting()
System.Void TryLogin()
System.Void SetSessionParam(app.network.api.Enum.InviteCategory inviteType, System.String sessionKey)
app.InviteManager.ExternalInviteSessionParam GetSessionParam()
app.constant.scn.Index UpdateFlow()
System.Boolean IsInviteRequest()
System.String GetInviteCode(via.Language language)
System.String GetInviteMessage(via.Language language)
System.Void doStart()
System.Void doOnDestroy()
System.Void .ctor()

describe app.BattleUploadManager

app.BattleUploadManager : app.SingletonBaseBehavior`1<app.BattleUploadManager>

fields
static System.Boolean IsGroupParameter
System.Boolean <IsValid>k__BackingField
System.Boolean <IsBusy>k__BackingField
System.Boolean <IsEnableUpload>k__BackingField
app.BattleUploadManager.UploadPhase Phase
app.BattleUploadManager.UploadRequest CurrentRequest
System.Collections.Generic.List`1<app.BattleUploadManager.UploadRequest> RequestList
System.Boolean IsResponse

methods
System.Boolean get_IsValid()
System.Void set_IsValid(System.Boolean value)
System.Boolean get_IsBusy()
System.Void set_IsBusy(System.Boolean value)
System.Boolean get_IsEnableUpload()
System.Void set_IsEnableUpload(System.Boolean value)
System.Void EnableUpload()
System.Void DisableUpload()
System.Void Reqeust(System.String battleId, System.String replayUri, System.String learningUri, System.Byte[] replayData)
System.Void doAwake()
System.Void doUpdate()
System.Void .ctor()
System.Void <doUpdate>b__23_0(System.Byte[] bytes)
System.Void <doUpdate>b__23_1()
System.Void <doUpdate>b__23_3()

describe app.BattleWatchManager

app.BattleWatchManager : app.SingletonBaseBehavior`1<app.BattleWatchManager>

fields
static System.Single HeartBeatIntervalTime
static System.Int32 FaceAppealInputMax
static System.Boolean IsGroupParameter
System.Boolean <IsValid>k__BackingField
System.Boolean <IsBusy>k__BackingField
System.Boolean <IsActive>k__BackingField
app.BattleWatchManager.BattleWatchRequestType <RequestType>k__BackingField
System.String <WatchToken>k__BackingField
app.BattleWatchManager.BattleWatchResult <WatchResult>k__BackingField
System.String <BattleId>k__BackingField
app.BattleWatchManager.BattleWatchSetting <BattleSetting>k__BackingField
System.Collections.Generic.List`1<app.FaceAppealInputParam> FaceAppealInputList
System.Boolean <IsTransitioning>k__BackingField
System.Boolean <IsNotViewKey>k__BackingField
System.Boolean <IsNotViewAttackData>k__BackingField
System.Boolean <IsNotViewFrameValue>k__BackingField
app.BattleWatchManager.BattleWatchPhase Phase
System.Boolean IsPhaseStart
System.Action`1<app.network.NetworkResult> Callback
System.Boolean IsAbort
System.Single HeartBeatTime
System.Collections.Generic.List`1<app.network.rpc.MessagingSessionRpc.WatchReceive.DataObject> KeyFrameList
System.Int32 KeyFrameCount
app.battle.SnapShot SnapShot
app.battle.SkipData SkipData
System.UInt32 FrameCounter
System.UInt32[] OverrideInput
System.Boolean IsReceiveSnapShot
app.DemoSkipParam DemoSkipData
System.Single AbortWaitTimeoutSec
System.Single AbortWaitElapsedSec
System.Boolean IsReconnecting
System.Nullable`1<System.Boolean> IsReconnectSuccess
System.Single ReconnectWaitTimeoutSec
System.Single ReconnectWaitElapsedSec
System.Collections.Generic.Queue`1<app.BattleWatchManager.BattleSendData> BattleSendDataQueue
app.BattleWatchManager.BattleSendData CurrentBattleSendData
System.Boolean IsBattleSendDataSending
System.Int64 BattleDataSequenceNo
System.UInt32 LatestDataNo
System.Int32 LatestState
System.Int64 LatestStartIndex
System.Boolean _IsForceReturnFlow

methods
System.Boolean get_IsValid()
System.Void set_IsValid(System.Boolean value)
System.Boolean get_IsBusy()
System.Void set_IsBusy(System.Boolean value)
System.Boolean get_IsActive()
System.Void set_IsActive(System.Boolean value)
app.BattleWatchManager.BattleWatchRequestType get_RequestType()
System.Void set_RequestType(app.BattleWatchManager.BattleWatchRequestType value)
System.String get_WatchToken()
System.Void set_WatchToken(System.String value)
app.BattleWatchManager.BattleWatchResult get_WatchResult()
System.Void set_WatchResult(app.BattleWatchManager.BattleWatchResult value)
System.String get_BattleId()
System.Void set_BattleId(System.String value)
app.BattleWatchManager.BattleWatchSetting get_BattleSetting()
System.Void set_BattleSetting(app.BattleWatchManager.BattleWatchSetting value)
System.Boolean get_IsWatchSetting()
System.Int32 get_WatchKeyCount()
System.Boolean get_IsSpectateFlow()
System.Boolean get_IsForceReturnFlow()
System.Boolean get_IsTransitioning()
System.Void set_IsTransitioning(System.Boolean value)
System.Boolean get_IsNotViewKey()
System.Void set_IsNotViewKey(System.Boolean value)
System.Boolean get_IsNotViewAttackData()
System.Void set_IsNotViewAttackData(System.Boolean value)
System.Boolean get_IsNotViewFrameValue()
System.Void set_IsNotViewFrameValue(System.Boolean value)
System.Boolean RequestStart(app.BattleWatchManager.BattleWatchRequestType requestType, System.String token, System.Action`1<app.network.NetworkResult> callback)
System.Void RequestEnd()
System.Void ErrorEnd()
System.Void SendHeartBeat()
System.Void SendBattleId(System.String battleId)
System.Void SendBattleSetting(app.FGBattleWatchParam battleSetting, System.Boolean isRestart)
System.Void SendBattleSetting(app.WTBattleWatchParam battleSetting, System.Boolean isRestart)
System.Void SendKeyFrame(System.Byte[] buffer)
System.Void SendFightContinue()
System.Void SendSkipData(app.battle.SkipData skipData, System.Boolean isRecoveryBattleSkipData)
System.Void SendSnapShot(app.battle.SnapShot snapShot)
System.Void SendDemoSkip(app.DemoSkipParam sendData)
System.Void AddFaceAppealInput(System.Int32 memberIndex, app.esports.FighterEmoteCtrl.EmoteState emoteState, System.Single inputTime)
System.Void SendFaceAppealInput(app.FaceAppealInputParam sendData)
System.Void SendFightError(app.error.ErrorCode errorCode)
app.FGBattleWatchParam GetFGBattleSetting()
app.WTBattleWatchParam GetWTBattleSetting()
System.Byte[] GetKeyFrame()
System.Boolean get_IsSkipData()
System.Boolean get_IsSnapShotData()
app.battle.SkipData GetSkipData()
app.battle.SnapShot GetSnapShot()
app.DemoSkipParam GetDemoSkipData()
System.Void SetSnapShot(app.battle.SnapShot snapShot)
System.Int32 GetMaxRoundNum()
System.UInt32 GetLatestFrame()
System.Void SetForceReturnFlow(System.Boolean isReturn)
System.Void SetUINotView(System.Boolean isNotKey, System.Boolean isNotAtkData, System.Boolean isNotFrame)
System.Void UpdateBattleDataSend()
System.Void UpdateBattleWatchPhase()
System.Void StartPhase(app.BattleWatchManager.BattleWatchPhase phase)
System.Void UpdatePhase(System.Action update, System.Action start)
System.Void AbortPhase()
System.Void ReconnectPhase()
System.Void Reset()
System.Boolean IsConnect()
System.Void RegisterBattleCallback()
System.Void RegisterWatchCallback()
System.Void UnregisterCallback()
System.Void CallbackReconnect()
System.Void CallbackReconnectComplete(System.Boolean isSuccess)
System.Void ClearBattleParam()
System.Void ClearWatchParam()
System.Void ReceiveFightId(app.network.rpc.MessagingSessionRpc.WatchReceive.DataObject data)
System.Void ReceiveBattleSetting(app.network.rpc.MessagingSessionRpc.WatchReceive.DataObject data)
System.Void ReceiveKeyFrame(app.network.rpc.MessagingSessionRpc.WatchReceive.DataObject data)
System.Void ReceiveSnapShot(app.network.rpc.MessagingSessionRpc.WatchReceive.DataObject data)
System.Void ReceiveFaceAppealInput(app.network.rpc.MessagingSessionRpc.WatchReceive.DataObject data)
System.Void ReceiveDemoSkip(app.network.rpc.MessagingSessionRpc.WatchReceive.DataObject data)
System.Boolean CheckEndKeyFrame()
System.Boolean AddFrameCounter(System.Byte[] buff, System.Boolean isReceive)
System.Int64 GetAndIncrementBattleDataSequenceNo()
System.Void StartPrivilege()
System.Void StartSetupBattle()
System.Void StartConnectBattle()
System.Void UpdateConnectBattle()
System.Void StartActiveBattle()
System.Void UpdateActiveBattle()
System.Void StartDisconnectBattle()
System.Void StartReconnectBattle()
System.Void StartSetupWatch()
System.Void StartConnectWatch()
System.Void UpdateConnectWatch()
System.Void StartActiveWatch()
System.Void UpdateActiveWatch()
System.Void StartDisconnectWatch()
System.Void UpdateDisconnectWatch()
System.Void StartReconnectWatch()
System.Void StartAbort()
System.Void UpdateAbort()
System.Void StartReconnect()
System.Void UpdateReconnect()
System.Void doStart()
System.Void doUpdate()
System.Void doOnDestroy()
System.Void .ctor()
System.Void <SendSnapShot>b__104_0(System.Byte[] compressData)
System.Void <UpdateBattleDataSend>b__124_0(app.network.rpc.MessagingSessionRpc.FightSendResponse res)
System.Void <UpdateBattleDataSend>b__124_1(app.network.rpc.MessagingSessionRpc.FightContinueResponse res)
System.Void <UpdateBattleDataSend>b__124_2(app.network.rpc.MessagingSessionRpc.FightEndResponse res)
System.Void <RegisterWatchCallback>b__133_0(app.network.rpc.MessagingSessionRpc.WatchNotify ntc)
System.Void <RegisterWatchCallback>b__133_1(app.network.rpc.MessagingSessionRpc.WatchReceive ntc)
System.Void <ReceiveSnapShot>b__142_0(System.Byte[] decompressData)
System.Boolean <ReceiveSnapShot>g__isSnapshot|142_1()
System.Void <StartPrivilege>b__148_0(app.error.ErrorCode errorCode, app.network.PrivilegeType checkType, System.Boolean isPrivilege)
System.Void <StartPrivilege>b__148_1()
System.Void <StartConnectBattle>b__150_0(app.network.rpc.MessagingSessionRpc.FightBeginResponse res)
System.Void <StartReconnectBattle>b__155_0(app.network.rpc.MessagingSessionRpc.FightRecoveryResponse res)
System.Void <StartConnectWatch>b__157_0(app.network.rpc.MessagingSessionRpc.WatchBeginResponse res)
System.Void <StartDisconnectWatch>b__161_0(app.network.rpc.MessagingSessionRpc.WatchEndResponse res)
System.Void <StartReconnectWatch>b__163_0(app.network.rpc.MessagingSessionRpc.WatchRecoveryResponse res)

describe app.BattleReplayDataManager

app.BattleReplayDataManager : app.SingletonBaseBehavior`1<app.BattleReplayDataManager>

fields
System.Boolean IsResultReplay
System.Boolean IsTrainingReplay
System.Collections.Generic.Dictionary`2<System.UInt32,app.error.ErrorCode> ResultReplayCheckResultDic
System.Collections.Generic.List`1<app.BattleReplaySaveData> BattleReplayTmpSaveDataForLocalList
System.Boolean IsAddReplayUpdate
app.BattleReplayDataManager.EState _CurrentState
app.BattleReplayDataManager.EState _PrevState
app.BattleReplayDataManager.EState _ErrorReturnState
System.Action _CurrentStateAction
app.BattleReplayListSaveData _LoadListData
System.Collections.Generic.List`1<app.BattleReplayDataManager.ReplaySaveQueueData> _SaveQueue
System.Collections.Generic.List`1<app.BattleReplayDataManager.ReplayLoadQueData> _LoadQueue
via.storage.saveService.SaveResult _ErrorResult
app.DialogSharingData _DialogData
app.BattleReplayListSaveData _Data
app.BattleReplayDataManager.OnLoadedDelegate _OnLoaded
System.Int32 _LastLoadSlot
System.Int32 _LastSaveSlot
System.Boolean <ReqDownloadError>k__BackingField
System.Boolean <IsReqDownload>k__BackingField
System.Collections.Generic.List`1<System.String> EnjoyCheckTargetReplayIdList
System.Collections.Generic.List`1<System.String> EnjoyedReplayIdList
System.Collections.Generic.List`1<app.BattleReplayDataManager.ReplayingData> _ReplayList
System.Int32 _CurrentReplayID
app.constant.FlowMap.eID _ReturnMap
app.constant.scn.Index _ReturnScene
System.Boolean _IsRequestFlow
System.Int32 _WaitTime
System.Boolean _IsForceReturnFlow
app.battle.BattleDesc _ResultReplayDesc
System.Boolean <IsActiveRewind>k__BackingField
app.battle.uBattleCore <BattleCore_>k__BackingField
app.CameraBehavior <CameraBehavior_>k__BackingField
System.Collections.Generic.Dictionary`2<System.Int32,app.BattleReplayDataManager.SnapShotAfterImagePlayerData> <SnapShotAfterImagePlDataPairs_>k__BackingField
System.Collections.Generic.Dictionary`2<System.Int32,System.Collections.Generic.List`1<app.esports.bBattleAfterImage>> <AfterImageDict_>k__BackingField
app.FlowController <FlowController_>k__BackingField
System.Int32 <RollbackFrame_>k__BackingField
System.Int32 <RewindFrame_>k__BackingField
System.Int32 <RollforwardFrame_>k__BackingField
via.render.CapturePlane <CapturePlane_>k__BackingField
via.threading.SimpleReaderWriterLock <SnapShotLock_>k__BackingField
System.Action <OnEndEvent>k__BackingField

methods
System.UInt32 get_SaveDataVersion()
System.UInt32 get_SaveDataHash()
System.Boolean get_IsBusy()
System.Int32 get_LastSaveSlot()
System.Int32 get_LastLoadSlot()
System.Void .ctor()
System.Void doStart()
System.Void doUpdate()
System.Void doOnDestroy()
System.Void Init()
System.Void Save(app.BattleReplaySaveData saveData, System.Action onSaved)
System.Void Load(System.Action`1<app.BattleReplaySaveData[]> on_loaded, System.Int32 slotNo)
app.BattleReplaySaveData CreateSaveData(app.battle.BattleDesc desc, System.Byte[] replayData, app.battle.bBattleFlow.MatchData resultData, app.battle.uBattleCore battleCore)
System.Void RegisterSaveData()
System.Void UnregisterSaveData()
app.storage.SaveDataBase SaveSaveData()
System.Void LoadSaveData(app.storage.SaveDataBase data)
System.Void DelayLoadSaveData()
app.storage.SaveDataBase ConvertSaveData(app.storage.SaveDataBase data)
System.Void SetBattleReplayTmpDataForResultList(app.BattleReplaySaveData data, app.network.api.HatoClientAPI.Component.CommonReplayInfo info)
System.Collections.Generic.List`1<app.BattleReplayDataManager.BattleReplayTmpData> GetValidBattleReplayTmpDataForResultList()
System.Void ChangeState(app.BattleReplayDataManager.EState state)
System.Void queCheck()
System.Void save_Load_Start()
System.Void save_Load_Now()
System.Void save_Start()
System.Void save_Now()
System.Void save_End()
System.Void save_Error_Start()
System.Void save_Error_Now()
System.Void save_Error_End()
System.Void load_Start()
System.Void load_Now()
System.Void load_End()
System.Void load_Error_Start()
System.Void load_Error_Now()
System.Void load_Error_End()
System.Void delete_Start()
System.Void delete_Now()
System.Void delete_End()
System.Boolean RequestSaveData(app.BattleReplayListSaveData data, System.Int32 slotNo)
System.Boolean RequestLoadData(app.BattleReplayDataManager.OnLoadedDelegate on_loaded, System.Int32 slotNo)
System.Boolean RequestRemoveData(System.Int32 slotNo)
System.Void Loaded(app.BattleReplayListSaveData data)
System.Void Trace(System.Object data, System.Int32 traceType, System.String mName, System.String pName)
System.Boolean get_IsForceReturnFlow()
System.Boolean get_ReqDownloadError()
System.Void set_ReqDownloadError(System.Boolean value)
System.Boolean get_IsRequestFlow()
System.Boolean get_IsReplayFlow()
System.Boolean get_IsReqDownload()
System.Void set_IsReqDownload(System.Boolean value)
System.Int32 get_ReplayDataCount()
System.Int32 get_CurrentReplayID()
System.Void set_CurrentReplayID(System.Int32 value)
System.Int32 get_WaitTime()
System.Void set_WaitTime(System.Int32 value)
System.Int32 get_NextReplayID()
System.Int32 get_PrevReplayID()
app.constant.scn.Index get_ReturnScene()
app.constant.FlowMap.eID get_ReturnMap()
System.Void Release()
System.Void SetForceReturnFlow(System.Boolean isReturn)
System.Void RequestReplayFlow(System.Boolean isRequest)
System.Void SetReplayDownLoad(System.Boolean isDownload)
System.Void SetDownLoadError(System.Boolean isError)
System.Void AddReplayData(app.BattleReplayData bReplayData, System.String replayId, app.network.api.HatoClientAPI.Component.CommonReplayInfo replayInfo, System.Boolean isRivalAi, app.network.api.Enum.ReplayPlaybackClientTab replayTab)
System.Void AddRangeReplayData(app.BattleReplayDataManager.ReplayingData[] bReplayDatas)
System.Void RemoveReplayData(app.BattleReplayDataManager.ReplayingData bReplayData)
System.Void RemoveAtReplayData(System.Int32 index)
System.Void ClearReplayData()
app.BattleReplayDataManager.ReplayingData GetReplayData()
app.BattleReplayDataManager.ReplayingData GetReplayData(System.Int32 index)
System.Void SetReturnFlow(app.constant.FlowMap.eID map, app.constant.scn.Index scene)
System.Void GetReplayDesc(app.battle.BattleDesc desc)
System.Void SetReplayDesc(app.battle.BattleDesc desc)
System.Void ClearReplayDesc()
System.Void SetTransitionInfoToTraining()
System.Boolean get_IsActiveRewind()
System.Void set_IsActiveRewind(System.Boolean value)
System.Boolean get_IsRewindNow()
System.Void EndFlow()
System.Void StartRewind(app.battle.uBattleCore battleCore)
System.Void RoundResetRewind()
System.Void ReleaseRewind()
System.Void BackFrame(System.Action endEvent, System.Int32 frame)
System.Void RollForward(System.Action endEvent, System.Int32 frame)
System.Void UpdateFlow()
System.Void AddAfterImage(System.Int32 plID, !!0 component)
System.Void SaveAfterImage(System.Int32 plID, System.UInt32 uniqueID, System.UInt32 stageTime)
System.Void LoadAfterImage(System.Int32 plID, System.UInt32 uniqueID, System.UInt32 stageTime)
System.Void AllHideAfterImage()
app.FlowController.EState onCapturePlane(app.FlowController.Status aStatus)
app.FlowController.EState onSnapShotLoad(app.FlowController.Status aStatus)
app.FlowController.EState onSnapShotLoad_Next(app.FlowController.Status aStatus)
app.FlowController.EState onLoadSnapShotWait(app.FlowController.Status aStatus)
app.FlowController.EState onRollForward(app.FlowController.Status aStatus)
app.FlowController.EState onRollForward_RollBack(app.FlowController.Status aStatus)
System.Void rollForward(System.Boolean isNext)
app.FlowController.EState onVfxUpdate(app.FlowController.Status aStatus)
app.FlowController.EState onAfterBackFrame(app.FlowController.Status aStatus)
System.Void onRollForwardEnd()
System.Void onRewindEnd()
System.Void onEnd()
System.Void onUpdateFrame()
!!0 FindComponentForScene()
app.battle.uBattleCore get_BattleCore_()
System.Void set_BattleCore_(app.battle.uBattleCore value)
app.CameraBehavior get_CameraBehavior_()
System.Void set_CameraBehavior_(app.CameraBehavior value)
System.Collections.Generic.Dictionary`2<System.Int32,app.BattleReplayDataManager.SnapShotAfterImagePlayerData> get_SnapShotAfterImagePlDataPairs_()
System.Void set_SnapShotAfterImagePlDataPairs_(System.Collections.Generic.Dictionary`2<System.Int32,app.BattleReplayDataManager.SnapShotAfterImagePlayerData> value)
System.Collections.Generic.Dictionary`2<System.Int32,System.Collections.Generic.List`1<app.esports.bBattleAfterImage>> get_AfterImageDict_()
System.Void set_AfterImageDict_(System.Collections.Generic.Dictionary`2<System.Int32,System.Collections.Generic.List`1<app.esports.bBattleAfterImage>> value)
app.FlowController get_FlowController_()
System.Void set_FlowController_(app.FlowController value)
System.Int32 get_RollbackFrame_()
System.Void set_RollbackFrame_(System.Int32 value)
System.Int32 get_RewindFrame_()
System.Void set_RewindFrame_(System.Int32 value)
System.Int32 get_RollforwardFrame_()
System.Void set_RollforwardFrame_(System.Int32 value)
via.render.CapturePlane get_CapturePlane_()
System.Void set_CapturePlane_(via.render.CapturePlane value)
via.threading.SimpleReaderWriterLock get_SnapShotLock_()
System.Void set_SnapShotLock_(via.threading.SimpleReaderWriterLock value)
System.Action get_OnEndEvent()
System.Void set_OnEndEvent(System.Action value)
System.Void <doStart>b__18_0(via.storage.saveService.SaveResult result)
System.Void <doStart>b__18_1(via.storage.saveService.SaveResult result)
static app.battle.FighterDesc <SetTransitionInfoToTraining>g__CreatePlayerInfo|122_0(app.TrainingSystemSaveData.PlayerData pl_data, System.Boolean isCpu)
System.Void <onSnapShotLoad_Next>b__151_0()```
