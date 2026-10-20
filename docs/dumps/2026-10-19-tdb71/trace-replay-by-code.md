# Trace of the manual replay-by-code flow (2026-10-19, plugin v0.1.8)

Dev page Trace panel, all ten hooks (MenuDecideEvent is virtual and cannot be hooked). Player typed replay ID B4ENK6EW8, pressed the result, pressed Watch Replay. Oldest first in the raw log is at the bottom; page log is newest first. Later entries at 9:29 are the page calling `OnResultCallback` on the stale flow instance #1.

```
9:27:53 PM · trace

103.036s app.network.api.HatoClientAPI.Api.Replay.PostSearchReplayId(this=#4 app.network.api.HatoClientAPI.Api.Replay, a1=#5 app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdIn, a2=#6 System.Action`1<app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdOut>, a3=#7 System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput>)

9:27:53 PM · trace

103.036s app.UICFNReplayTopTabSearchChildSearchId.CallSearchReplayIdApiFlow.OnCallApi(this=#3 app.UICFNReplayTopTabSearchChildSearchId.CallSearchReplayIdApiFlow)

9:27:57 PM · trace

107.468s app.BattleReplayDataManager.AddReplayData(this=#14 app.BattleReplayDataManager, a1=#15 app.BattleReplayData, a2="B4ENK6EW8", a3=#16 app.network.api.HatoClientAPI.Component.CommonReplayInfo, a4=false:System.Boolean, a5=99:app.network.api.Enum.ReplayPlaybackClientTab)

9:28:27 PM · trace

137.900s app.UICFNReplaySearchResult.Start(this=0x200104fa670:this(static), a1=#21 System.Action)  → ret=#22 app.UIFlowManager.Handle

9:28:46 PM · trace

copied 9 calls

9:28:44 PM · trace

copied 9 calls

9:28:42 PM · trace stop

BridgeError: timed out after 5000 ms

9:28:27 PM · trace

137.900s app.UICFNReplaySearchResult.Start(this=0x200104fa670:this(static), a1=#21 System.Action)  → ret=#22 app.UIFlowManager.Handle

9:27:57 PM · trace

107.468s app.BattleReplayDataManager.AddReplayData(this=#14 app.BattleReplayDataManager, a1=#15 app.BattleReplayData, a2="B4ENK6EW8", a3=#16 app.network.api.HatoClientAPI.Component.CommonReplayInfo, a4=false:System.Boolean, a5=99:app.network.api.Enum.ReplayPlaybackClientTab)

9:28:27 PM · trace

137.900s app.UICFNReplaySearchResult.Start(this=0x200104fa670:this(static), a1=#21 System.Action)  → ret=#22 app.UIFlowManager.Handle

9:27:57 PM · trace

107.468s app.BattleReplayDataManager.AddReplayData(this=#14 app.BattleReplayDataManager, a1=#15 app.BattleReplayData, a2="B4ENK6EW8", a3=#16 app.network.api.HatoClientAPI.Component.CommonReplayInfo, a4=false:System.Boolean, a5=99:app.network.api.Enum.ReplayPlaybackClientTab)

9:28:27 PM · trace

137.900s app.UICFNReplaySearchResult.Start(this=0x200104fa670:this(static), a1=#21 System.Action)  → ret=#22 app.UIFlowManager.Handle

9:27:57 PM · trace

107.468s app.BattleReplayDataManager.AddReplayData(this=#14 app.BattleReplayDataManager, a1=#15 app.BattleReplayData, a2="B4ENK6EW8", a3=#16 app.network.api.HatoClientAPI.Component.CommonReplayInfo, a4=false:System.Boolean, a5=99:app.network.api.Enum.ReplayPlaybackClientTab)

9:28:27 PM · trace

137.756s app.network.api.HatoClientAPI.Api.Replay.PostSearchReplayId(this=#17 app.network.api.HatoClientAPI.Api.Replay, a1=#18 app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdIn, a2=#19 System.Action`1<app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdOut>, a3=#20 System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput>)

9:27:57 PM · trace

107.468s app.BattleReplayDataManager.AddReplayData(this=#14 app.BattleReplayDataManager, a1=#15 app.BattleReplayData, a2="B4ENK6EW8", a3=#16 app.network.api.HatoClientAPI.Component.CommonReplayInfo, a4=false:System.Boolean, a5=99:app.network.api.Enum.ReplayPlaybackClientTab)

9:27:57 PM · trace

107.051s app.network.api.HatoClientAPI.Api.Replay.PostDownloadUrl(this=#10 app.network.api.HatoClientAPI.Api.Replay, a1=#11 app.network.api.HatoClientAPI.Component.PostReplayDownloadUrlIn, a2=#12 System.Action`1<app.network.api.HatoClientAPI.Component.PostReplayDownloadUrlOut>, a3=#13 System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput>)

9:27:55 PM · trace

105.568s app.UICFNReplayInfo.Start(this=0x2002d7e4cb0:this(static), a1=#8 System.Action)  → ret=#9 app.UIFlowManager.Handle

9:27:53 PM · trace

103.036s app.network.api.HatoClientAPI.Api.Replay.PostSearchReplayId(this=#4 app.network.api.HatoClientAPI.Api.Replay, a1=#5 app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdIn, a2=#6 System.Action`1<app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdOut>, a3=#7 System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput>)

9:27:53 PM · trace

103.036s app.UICFNReplayTopTabSearchChildSearchId.CallSearchReplayIdApiFlow.OnCallApi(this=#3 app.UICFNReplayTopTabSearchChildSearchId.CallSearchReplayIdApiFlow)

9:27:53 PM · trace

103.036s app.network.api.HatoClientAPI.Api.Replay.PostSearchReplayId(this=#4 app.network.api.HatoClientAPI.Api.Replay, a1=#5 app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdIn, a2=#6 System.Action`1<app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdOut>, a3=#7 System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput>)

9:27:53 PM · trace

103.036s app.UICFNReplayTopTabSearchChildSearchId.CallSearchReplayIdApiFlow.OnCallApi(this=#3 app.UICFNReplayTopTabSearchChildSearchId.CallSearchReplayIdApiFlow)

9:27:53 PM · trace

103.036s app.network.api.HatoClientAPI.Api.Replay.PostSearchReplayId(this=#4 app.network.api.HatoClientAPI.Api.Replay, a1=#5 app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdIn, a2=#6 System.Action`1<app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdOut>, a3=#7 System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput>)

9:27:53 PM · trace

103.036s app.UICFNReplayTopTabSearchChildSearchId.CallSearchReplayIdApiFlow.OnCallApi(this=#3 app.UICFNReplayTopTabSearchChildSearchId.CallSearchReplayIdApiFlow)

9:27:53 PM · trace

103.036s app.network.api.HatoClientAPI.Api.Replay.PostSearchReplayId(this=#4 app.network.api.HatoClientAPI.Api.Replay, a1=#5 app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdIn, a2=#6 System.Action`1<app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdOut>, a3=#7 System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput>)

9:27:53 PM · trace

103.036s app.UICFNReplayTopTabSearchChildSearchId.CallSearchReplayIdApiFlow.OnCallApi(this=#3 app.UICFNReplayTopTabSearchChildSearchId.CallSearchReplayIdApiFlow)

9:27:53 PM · trace

103.036s app.network.api.HatoClientAPI.Api.Replay.PostSearchReplayId(this=#4 app.network.api.HatoClientAPI.Api.Replay, a1=#5 app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdIn, a2=#6 System.Action`1<app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdOut>, a3=#7 System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput>)

9:27:53 PM · trace

103.036s app.UICFNReplayTopTabSearchChildSearchId.CallSearchReplayIdApiFlow.OnCallApi(this=#3 app.UICFNReplayTopTabSearchChildSearchId.CallSearchReplayIdApiFlow)

9:27:53 PM · trace

103.036s app.network.api.HatoClientAPI.Api.Replay.PostSearchReplayId(this=#4 app.network.api.HatoClientAPI.Api.Replay, a1=#5 app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdIn, a2=#6 System.Action`1<app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdOut>, a3=#7 System.Action`1<app.network.api.HatoClientAPI.Component.CommonErrorOutput>)

9:27:53 PM · trace

103.036s app.UICFNReplayTopTabSearchChildSearchId.CallSearchReplayIdApiFlow.OnCallApi(this=#3 app.UICFNReplayTopTabSearchChildSearchId.CallSearchReplayIdApiFlow)

9:27:53 PM · trace

103.033s app.UICFNReplayTopTabSearchChildSearchId.InputSearchIdWindowFlow.OnResultCallback(this=#2 app.UICFNReplayTopTabSearchChildSearchId.InputSearchIdWindowFlow, a1="B4ENK6EW8")

9:27:52 PM · trace

102.259s app.UICFNReplayTopTabSearchChildSearchId.InputSearchIdWindowFlow.OnEnter(this=#1 app.UICFNReplayTopTabSearchChildSearchId.InputSearchIdWindowFlow)

9:27:46 PM · trace

10 of 10 hooks installed; walk the replay flow in-game

9:27:46 PM · hook.add

#10 app.network.api.HatoClientAPI.Api.Replay.PostDownloadUrl

9:27:46 PM · hook.add

#9 app.network.api.HatoClientAPI.Api.Replay.PostSearchReplayId

9:27:46 PM · hook.add

#8 app.BattleReplayDataManager.AddReplayData

9:27:46 PM · hook.add

#7 app.UIFlowCFNCommon.CallReplayDownloadUrlApiFlow`1<app.UICFNReplayTopTabListBase.FlowParamBase>.OnCallApi

9:27:46 PM · hook.add

#6 app.UICFNReplayInfo.FlowParamBase.MenuDecideEvent

9:27:46 PM · hook.add

#5 app.UICFNReplayInfo.Start

9:27:46 PM · hook.add

#4 app.UICFNReplaySearchResult.Start

9:27:46 PM · hook.add

#3 app.UICFNReplayTopTabSearchChildSearchId.CallSearchReplayIdApiFlow.OnCallApi

9:27:46 PM · hook.add

#2 app.UICFNReplayTopTabSearchChildSearchId.InputSearchIdWindowFlow.OnResultCallback

9:27:46 PM · hook.add

#1 app.UICFNReplayTopTabSearchChildSearchId.InputSearchIdWindowFlow.OnEnter```

# Describe preset "Replay-by-ID flow"

```
9:32:32 PM · describe app.network.api.HatoClientAPI.Component.CommonReplayPlayerInfo

app.network.api.HatoClientAPI.Component.CommonReplayPlayerInfo : System.Object

fields
System.Boolean allow_cross_play
System.Int32 battle_input_type
System.UInt32 character_id
System.UInt32 home_id
System.Int32 league_point
System.UInt32 league_rank
app.network.api.HatoClientAPI.Component.CommonCircleMainCircleInfo main_circle
System.UInt32 master_league
System.Int32 master_rating
System.Int32 master_rating_ranking
app.network.api.HatoClientAPI.Component.CommonFighterPersonalInfo player
System.UInt32 playing_character_id
System.Collections.Generic.List`1<System.UInt32> round_results
System.UInt32 title_plate

methods
System.Void .ctor()

9:32:32 PM · describe app.network.api.HatoClientAPI.Component.CommonReplayDownloadInfo

app.network.api.HatoClientAPI.Component.CommonReplayDownloadInfo : System.Object

fields
System.String replay_id
System.String url

methods
System.Void .ctor()

9:32:32 PM · describe app.UICFNReplayTopTabSearchChildSearchId.MainFlow

app.UICFNReplayTopTabSearchChildSearchId.MainFlow : app.UIFlow`1<app.UICFNReplayTopTabSearchChildSearchId.FlowParam>

fields


methods
System.Void OnEnter()
System.Void OnExit()
System.Void .ctor()

9:32:32 PM · describe app.UITextInputDialog

app.UITextInputDialog : app.UIWidget

fields
static System.Collections.Generic.Dictionary`2<app.UITextInputDialog.RequestType,app.UITextInputDialog.ReqInfo> RequestDataTable
app.UITextInputDialog.ResultFunc ResultEvent
app.UIPartsGroup MainGroup
app.UIPartsGroupItem DecideButton
app.UIPartsSimpleList DecideButtonList
app.UIPartsTextInput TextInputParts
via.gui.Text TextInputElement
via.gui.Text TextErrorElement
via.gui.Panel TextFormPanel
System.Boolean CanFinish
System.String DefaultMessage
System.String CurremtMessage
System.UInt32 DefaultStatePattern
app.UITextInputDialog.RequestType CurrentRequestType
app.UITextInputDialog.VisualType CurrentVisualType
System.Boolean BgBlackEnable
static System.Char[] _AdditionalWhiteSpaceChar

methods
System.Boolean get_FADE_OUT_DESTROY()
System.Void InvokeResultEvent(System.String inputText)
System.Void SetupDefaultMessage(System.String default_message)
static app.UITextInputDialog OpenTextInputDialog(app.UITextInputDialog.ResultFunc resultFunc, app.UITextInputDialog.RequestType requestType, app.UITextInputDialog.VisualType visualType, System.String defaultMessage, System.UInt32 priority)
System.Void Decide()
System.Void Cancel()
System.Void InputEvent_Decide()
System.Void InputEvent_Cancel()
System.Void CallDecideSound()
System.Void CallCancelSound()
System.Void CallNgSound()
System.Void SetFixedText(System.String text)
System.String GetColorNgWord(System.String check_str, System.String ng_result)
System.Boolean CheckNumricNum(System.String check_str)
System.Boolean CheckNumricOnly(System.String check_str)
System.Void ChangeErrorView(System.Boolean flg)
System.Boolean Init()
System.Void SetupText()
System.Void SetupErrorText()
System.Void SetupNumricLimitErrorText()
System.Void SetupErrorTextMinimumEntry()
System.Boolean CheckCanSelect(System.Int32 index)
System.Boolean FlowEvent_Setup()
System.Void FlowEvent_BeforeShow()
System.Void FlowEvent_AfterHide()
app.UIAgentSimpleInputDelegates FlowEvent_InputEventRegister()
System.Boolean CanCancel()
System.Void .ctor()
static System.Void .cctor()
System.Void <Init>b__43_0(app.UIPartsTextInput.Device device, System.String text)

9:32:32 PM · describe app.UIFlowBase

app.UIFlowBase : app.UIStateBase

fields


methods
app.IUIFlowObjectManager get_ObjectManager()
System.Void .ctor()

9:32:32 PM · describe app.UIFlowAPI`1<app.UICFNReplayTopTabSearchChildSearchId.FlowParam>

app.UIFlowAPI`1<app.UICFNReplayTopTabSearchChildSearchId.FlowParam> : app.UIFlowAPIBase`1<app.UICFNReplayTopTabSearchChildSearchId.FlowParam>

fields


methods
System.Boolean get_EnableInput()
System.Void OnEnter()
System.Void OnExit()
System.Void .ctor()

9:32:32 PM · describe app.UIFlow`1<app.UICFNReplayTopTabSearchChildSearchId.FlowParam>

app.UIFlow`1<app.UICFNReplayTopTabSearchChildSearchId.FlowParam> : app.UIFlowBase

fields


methods
app.UICFNReplayTopTabSearchChildSearchId.FlowParam get_Param()
System.Boolean OnNew(app.UICFNReplayTopTabSearchChildSearchId.FlowParam param)
System.Boolean OnNew()
System.Void .ctor()

9:32:32 PM · describe app.IUIFlowHandle

app.IUIFlowHandle

fields


methods
app.UIFlowFlag get_Flags()
System.Boolean get_IsEnd()
System.Boolean Is()
app.UIFlowParamBase GetParam()
!!0 GetParam()
System.Void Next(app.UIFlowParamBase param)
System.Void Next()
System.Void End()

9:32:32 PM · describe app.UIFlowCFNCommon.ChildTabFlowData

app.UIFlowCFNCommon.ChildTabFlowData : System.Object

fields
app.IUIFlowHandle _FlowHandle
System.Action`3<app.IUIFlowHandle,app.UIAgent,System.Boolean> _ShowRequestAction
System.Action`2<app.IUIFlowHandle,System.Boolean> _HideRequestAction
System.Func`2<app.IUIFlowHandle,System.Boolean> _IsMainCheck

methods
System.Void .ctor(app.IUIFlowHandle handle, System.Action`3<app.IUIFlowHandle,app.UIAgent,System.Boolean> showRequest, System.Action`2<app.IUIFlowHandle,System.Boolean> hideRequest, System.Func`2<app.IUIFlowHandle,System.Boolean> isMainCheck)
app.IUIFlowHandle get_FlowHandle()
System.Void ShowRequest(app.UIAgent agent, System.Boolean isTabChanged)
System.Void HideRequest(System.Boolean isTabChanged)
System.Boolean IsMain()

9:32:32 PM · describe app.UIFlowManager

app.UIFlowManager : app.SingletonBaseBehavior`1<app.UIFlowManager>

fields
static via.threading.SimpleReaderWriterLock _LockHandles
System.Collections.Generic.List`1<app.UIFlowManager.Handle> _Handles
app.UIFlowManager.Flag _Flags

methods
static System.Boolean get_IsInput()
static System.Boolean get_Updating()
static app.IUIFlowHandle Start(!!1 param, System.String[] tags, app.UIFlowFlag flags)
static app.IUIFlowHandle Start(System.String[] tags, app.UIFlowFlag flags)
static app.IUIFlowHandle Start(app.UIFlowParamBase param, System.String[] tags, app.UIFlowFlag flags)
static System.Void End(app.IUIFlowHandle handle)
static System.Void End(System.String[] tags)
static app.IUIFlowHandle[] GetHandles(System.String[] tags)
static System.Boolean Active(app.IUIFlowHandle handle)
System.Void doLateUpdate()
System.Void AddHandle(app.UIFlowManager.Handle handle)
System.Void UpdateFlags()
System.String GetStrOnExceptionKPI(app.UIAgent agent)
System.Void .ctor()
static System.Void .cctor()```
