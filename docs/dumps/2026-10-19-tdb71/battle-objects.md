# Battle objects from Training Mode (2026-10-19, TDB 71)

Dev page "Describe battle objects": `app.battle.stats.BattleStatsManager`, the static `gBattle` holder, `app.battle.uBattleCore` (from `BattleTimeLineManager._BattleCore`) and `app.PlayerBehavior` (from `_PlayerBehaviors[0]`). `PlayerBehavior` is motion/VFX/physics presentation; the gameplay state is behind the `gBattle` statics (`Player`, `Team`, `Training`, `Input`, `Command`, `Rollback`).

```
8:15:34 PM · describe app.battle.stats.BattleStatsManager

app.battle.stats.BattleStatsManager : app.SingletonBaseBehavior`1<app.battle.stats.BattleStatsManager>

fields
System.UInt32 <StageTimer>k__BackingField
System.UInt32 <TimeOutTimer>k__BackingField
System.Int32 <TargetPlayerID>k__BackingField
System.Boolean <IsReplaySave>k__BackingField
app.BattleReplaySaveData <ReplaySaveData>k__BackingField
System.Boolean <IsStartFlow>k__BackingField
System.Collections.Generic.List`1<app.INotify> <BattleStatsNotifies>k__BackingField
via.threading.SimpleReaderWriterLock mLock
app.battle.stats.BattleStatsData _StatsData
app.battle.stats.BattleStatsScoreData _ScoreData
app.FlowController _FlowController
app.battle.stats.BattleStatsManager.BattleLog _BattleLog
static System.Int32 RANDOM_RANGE
static System.Int32 WAIT_TIMEOUT_TIME

methods
System.Boolean get_IsEnded()
app.battle.stats.BattleStatsScoreData get_ScoreData()
app.battle.stats.BattleStatsData get_StatsData()
System.UInt32 get_StageTimer()
System.Void set_StageTimer(System.UInt32 value)
System.UInt32 get_TimeOutTimer()
System.Void set_TimeOutTimer(System.UInt32 value)
System.Int32 get_TargetPlayerID()
System.Void set_TargetPlayerID(System.Int32 value)
System.Boolean get_IsReplaySave()
System.Void set_IsReplaySave(System.Boolean value)
app.BattleReplaySaveData get_ReplaySaveData()
System.Void set_ReplaySaveData(app.BattleReplaySaveData value)
System.Boolean get_IsStartFlow()
System.Void set_IsStartFlow(System.Boolean value)
System.Collections.Generic.List`1<app.INotify> get_BattleStatsNotifies()
System.Void set_BattleStatsNotifies(System.Collections.Generic.List`1<app.INotify> value)
static System.Boolean ElectionMessage(app.battle.stats.BattleStatsScoreData scoreData, System.Collections.Generic.List`1<app.battle.stats.ResultMessageData> outMsgDataList, System.Func`2<System.UInt32,System.Boolean> isExNotFindEvent)
static System.Int32 GetMessageData(System.Collections.Generic.List`1<System.UInt32> msgIds, System.Action`2<System.Int32,app.battle.stats.MsgListData> onLoaded)
static System.Int32 GetStampConditionData(System.Int32 fighterId, System.Action`2<System.Int32,System.Collections.Generic.List`1<app.battle.stats.BattleStatsFighterData>> onLoaded)
static System.Boolean TryGetMessageData(System.Collections.Generic.List`1<System.UInt32> msgIds, app.battle.stats.MsgListData msdListData)
System.Void Restart()
System.Void EndWait(app.AppDefine.LeagueRankWithLevel aBeforeRank, app.AppDefine.LeagueRankWithLevel aAfterRank)
System.Void doUpdate()
System.Void doOnDestroy()
System.Void doOnEnable()
System.Void doOnDisable()
app.FlowController.EState load_start(app.FlowController.Status aStatus)
app.FlowController.EState load_update(app.FlowController.Status aStatus)
app.FlowController.EState battle_start(app.FlowController.Status aStatus)
app.FlowController.EState battle_update(app.FlowController.Status aStatus)
app.FlowController.EState battle_end(app.FlowController.Status aStatus)
app.FlowController.EState wait_update(app.FlowController.Status aStatus)
app.FlowController.EState end(app.FlowController.Status aStatus)
System.Void init()
static System.Void extractionScore(app.battle.stats.BattleStatsData statsData, app.battle.stats.BattleStatsScoreData scoreData, System.Int32 targetId, app.battle.stats.BattleStatsManager.BattleLog battleLog)
static System.Boolean electionMessage(app.battle.stats.BattleStatsScoreData scoreData, System.Collections.Generic.List`1<app.battle.stats.ResultMessageData> inMsgDataList, System.Int32 randomRange, System.Func`2<System.UInt32,System.Boolean> isExNotFindEvent)
System.Void save(System.Collections.Generic.List`1<app.battle.stats.ResultMessageData> resultMsgs)
System.Void .ctor()
static System.Void <load_start>g___proc_unload|45_2(System.Collections.Generic.List`1<via.Folder> _folders, app.ResourceLoadController.EEndType _endType)
System.Void <battle_update>g__GetNotifyDict|48_0(app.BattleRollback.StorageWork storage, System.Collections.Generic.Dictionary`2<System.Type,System.Collections.Generic.List`1<app.INotify>> notifyDict)
System.Boolean <battle_update>g__GetRoundData|48_1(app.BattleRollback.StorageWork storage, app.battle.stats.BattleStatsRoundData roundData)
System.Void <battle_update>g__Condition|48_2(app.BattleRollback.StorageWork storage, app.battle.stats.BattleStatsRoundData roundData, System.Collections.Generic.Dictionary`2<System.Type,System.Collections.Generic.List`1<app.INotify>> notifyDict)
static System.Void <battle_update>g__defaultCheck|48_11(app.battle.stats.BattleStatsManager.<>c__DisplayClass48_3 )
static System.Boolean <battle_update>g__isConditionCheck|48_9(app.battle.stats.BattleStatsRealtimeConditionData realTime, System.Int32 recursive)
static System.Void <battle_update>g__resetAllClear|48_10(app.battle.stats.BattleStatsRealtimeConditionData realTime)
System.Boolean <battle_end>g__isMasterVsMaster|49_0()
static System.Single <extractionScore>g__getScore|53_1(System.UInt32 count, app.battle.stats.BattleStatsConditionData condition)
static System.Boolean <extractionScore>g__isConditionCheck|53_2(System.UInt32 countSum, app.battle.stats.BattleStatsConditionData condition)
static System.Void <electionMessage>g___getResult|54_6(app.battle.stats.BattleStatsManager.<>c__DisplayClass54_0 , app.battle.stats.BattleStatsManager.<>c__DisplayClass54_1 )
static System.Void <electionMessage>g___getResultItemList|54_0(System.Collections.Generic.List`1<app.battle.stats.ResultMessageData> resultDataList, System.Collections.Generic.List`1<app.battle.stats.BattleStatsScoreItemData> praiseList, System.Collections.Generic.List`1<app.battle.stats.BattleStatsScoreItemData> suggestionList, System.Collections.Generic.List`1<app.battle.stats.BattleStatsScoreItemData> ignoreList, System.Func`2<System.UInt32,System.Boolean> isNotFindEvent, app.battle.stats.BattleStatsManager.<>c__DisplayClass54_0 )
static System.Boolean <electionMessage>g___ignoreIndexCheck|54_1(System.Collections.Generic.List`1<app.battle.stats.BattleStatsScoreItemData> messageList, System.Collections.Generic.List`1<app.battle.stats.BattleStatsScoreItemData> resultList, System.Int32 index)
static System.Boolean <electionMessage>g___ignoreCheck|54_2(System.Collections.Generic.List`1<app.battle.stats.BattleStatsScoreItemData> messageList, System.Collections.Generic.List`1<app.battle.stats.BattleStatsScoreItemData> resultList, app.battle.stats.BattleStatsRateData rateData)
app.battle.stats.RivalAiReplay.ReplayUiInfo.PlayerInfo <save>g__createPlayerInfo|55_0(app.battle.FighterDesc fDesc)

8:15:34 PM · describe gBattle

gBattle : System.Object

fields
static app.BattleSystem System
static app.BattleParameter Param
static app.BattleSetting Setting
static app.BattleResource Resource
static app.BattleFlow Flow
static app.BattleMove Move
static app.BattleTeam Team
static app.BattleInfo Info
static app.BattleSound Sound
static app.BattleJudge Judge
static app.BattleChronos Chronos
static app.BattleRound Round
static app.FBattleConfig Config
static app.FBattleCamera Camera
static app.FBattleMediator Mediator
static app.FBattleMission Mission
static app.FBattleTutorial Tutorial
static app.FBattleMiniGame MiniGame
static app.FBattleBonus Bonus
static app.FBattleInput Input
static app.sCommand Command
static nBattle.sPlayer Player
static nBattle.sWork Work
static nBattle.sGame Game
static app.BattleRollback Rollback
static app.TrainingInput Training
static app.esports.PlayerBehaviorManager PBManager
static app.BattleStats Stats

methods
static System.Void .cctor()
static System.UInt32 GetHitEffectDelayFrame()

8:15:34 PM · describe app.battle.uBattleCore

app.battle.uBattleCore : app.Unit

fields
static System.Int32 BattleInputIdMax
System.Boolean <IsBattleAllPause>k__BackingField
via.network.BattleInput.Error <SyncErrorType>k__BackingField
via.network.BattleInput m_input
System.Byte[] m_upload_replay_data
System.Boolean m_is_pause_input
System.Boolean m_is_started
System.Boolean m_is_pause
System.Boolean m_is_pause_prev
System.Boolean m_is_setuped_fixproj
System.Single m_delay_fixproj
System.Boolean m_is_display_stage
System.Int32 m_self_session_member_index
System.Boolean <m_is_fighter_change>k__BackingField
System.Int32 m_rollback_count
System.Boolean m_is_first_match
app.vfx.VfxActorEffectManager _AkebonoOwnerVfxManager
app.vfx.VfxID _AkebonoVfxID
System.Boolean _IsAkebono
app.battle.BattleDesc _Desc
System.Collections.Generic.List`1<app.battle.FighterDesc> _FighterDescs
System.Collections.Generic.List`1<via.GameObject> _Fighters
System.Collections.Generic.List`1<via.GameObject> _ResetupProjectiles
System.Collections.Generic.List`1<app.vfx.VfxActorEffectManager> _VfxManagers
System.Collections.Generic.List`1<via.relib.effect.behavior.ReLibMarkStampController> _StampControllers
app.DynamicInputLagData lag_data
soundlib.SoundContainableUserData arcadeSoundUserData1P
app.battle.BattleReplayController m_BRControl
System.Boolean IsSetGCTemp
System.Boolean Temp_LocalCollectionEnabled
System.Boolean Temp_AdaptiveGlobalCollection
System.Boolean Temp_AdaptiveCycleCollection
System.Int64[] RttSamle
System.Int32 RttSamplingIndex
System.Int32 CurrentInputLagStage
System.Int32 OverThresholdNum
static System.Int32 ROLLBACK_FRAME_DOWN_COUNT
System.Int32 m_rollback_frame_down_conter

methods
System.Int32 get_GameRound()
System.Int32 get_GameTime()
System.Int32 get_RollbackCount()
System.Int32 get_RollbackCountForDisplay()
System.Int32 get_ActualLagMin()
System.UInt32 get_OpponentRtt()
System.Collections.Generic.List`1<via.GameObject> get_Fighters()
System.Boolean get_IsRollforwarding()
System.Boolean get_IsStarted()
System.Boolean get_IsRecord()
System.Boolean get_IsSyncError()
System.Boolean get_IsBattleAllPause()
System.Void set_IsBattleAllPause(System.Boolean value)
via.network.BattleInput.Error get_SyncErrorType()
System.Void set_SyncErrorType(via.network.BattleInput.Error value)
via.network.BattleInput get_BattleInput()
System.Boolean get_m_is_fighter_change()
System.Void set_m_is_fighter_change(System.Boolean value)
app.battle.BattleReplayController get_BRControl()
System.Void .ctor(System.Int32 priority, via.GameObject go)
System.Void attach()
System.Void detach()
System.Void resetBattle()
System.Void startBattle(app.DynamicInputLagData data)
System.Void startBattle(System.Int32 input_delay)
System.Void startTrainingBattle(app.DynamicInputLagData data)
System.Void startTrainingBattle(System.Int32 input_delay)
System.Void endBattle(System.Boolean isKillEffects)
System.Void startRound(System.Int32 round)
System.Void startRound()
System.Void startTrainingRound()
System.Void stopRound()
System.Void startPredict()
System.Void modifyInputType()
System.Int32 getBattleInputSessionMemberIndex(System.Int32 battleInputId)
System.Void updateLocalInput()
System.Void updateFrame()
System.UInt32 getInput(System.Int32 plID)
System.Boolean isPaused()
System.Boolean isPaused_Replay()
System.Int32 getPauseCount()
System.Void updateCheckSum()
System.Void initDynamicInputLag()
System.Int32 calcOverThresholdNum()
System.Void updateDynamicInputLag()
System.Void start_spectate()
System.Void spectate()
System.Void end_spectate(System.Boolean isKillEffects)
System.Boolean is_ready_to_spectate()
System.Boolean is_spectate_error()
System.Void update_read()
System.Boolean is_spectate_first_round()
System.Boolean is_replay_first_round()
System.Void update_write()
System.Void setup_theme()
System.Void start_replay()
System.Boolean is_replay_ready()
System.Void init_round_replay()
System.Void replay(System.Boolean isContinue)
System.Void req_change_round(System.Int32 round)
System.Void pause_replay(System.Boolean isPause)
System.Void end_replay()
System.Boolean skip_replay(System.Int32 spaceFrame, System.Boolean isNext, System.Boolean isPause)
System.Boolean is_change_round_replay(System.Int32 round)
System.Boolean is_replay_error()
System.Boolean back_replay(System.Int32 frame, System.Boolean isPause)
System.Boolean isOnline()
System.Boolean finish()
System.Void onInputSyncError(via.network.BattleInput.Error err)
System.Void onReplayError(via.network.BattleReplay.Error err)
System.Void update(System.Int32 index, System.Int32 count)
System.Void updateDynamic(System.Single delta)
System.Void lateUpdate(System.Single delta)
System.Void asyncUpdate(System.Single delta)
System.Void asyncLateUpdate(System.Single delta)
System.Void setupBattleDesc(app.battle.BattleDesc desc)
System.Void setupRenderUserGlobalParam(app.battle.BattleDesc desc)
System.Void setupBattleRule(app.battle.BattleDesc desc)
System.Void setupFighterDesc(app.battle.BattleDesc desc)
via.GameObject setupFighter(app.battle.FighterDesc fdesc, System.Int32 player_id, System.Int32 team_id, via.GameObject[] shotObjs)
System.Void setupStandardFighter(via.GameObject fighter, app.battle.FighterDesc fdesc, System.Int32 player_id, System.Int32 team_id)
System.Void setupCustomizeFighter(via.GameObject fighter, app.battle.FighterDesc fdesc, System.Int32 player_id, System.Int32 team_id, via.GameObject[] shotObjs)
System.Void clearBattleDesc()
System.Void clearFighterDesc(System.Boolean isWTTeam)
System.Void clearFighter(System.Int32 player_id)
System.Void saveReplay(app.battle.bBattleFlow.MatchData resultData)
System.Byte[] getReplayData()
System.Boolean get_isExistCPU()
System.Void startAkebono()
System.Void endAkebono()
System.Void killEffects(System.Boolean isRemoveRespawnBuffEffect)
System.Void killEffects(System.UInt32[] playerIdAry)
System.Void killEffects_RollForward()
System.Void releaseStorageEffects()
System.Void setupStandardFighterResource(app.battle.FighterDesc fdesc, System.Int32 pid, System.Int32 team_id)
System.Void setupStandardFighterComponent(via.GameObject fighter, app.battle.FighterDesc fdesc, System.Int32 player_id, System.Int32 team_id)
System.Void validateFighter(app.battle.BattleDesc desc, app.battle.FighterDesc fdesc, System.Int32 pid, System.Int32 team_id)
System.Void arcadeBossBattleVoice(app.sound.SoundContainerApp sc, app.battle.FighterDesc fdesc, System.Int32 player_id, via.Folder folder)
System.Void characterGuideBattleVoice(app.sound.SoundContainerApp sc, app.battle.FighterDesc fdesc, System.Int32 player_id, via.Folder folder)
System.Void onLoadCustomizeData(System.Int32 pid)
System.Void setupCustomizeFighterResource(via.GameObject fighter, app.battle.FighterDesc fdesc, System.Int32 pid, System.Int32 team_id)
System.Void modifyAssisterBattleData(app.battle.FighterDesc fdesc)
System.Void setupCustomizeFighterComponent(via.GameObject fighter, app.battle.FighterDesc fdesc, System.Int32 player_id, System.Int32 team_id)
System.Void WTMasterSupportVoice(app.sound.SoundContainerApp sc, app.battle.FighterDesc fdesc, System.Int32 player_id, via.Folder folder)
System.Void setupFighterResource(app.battle.FighterDesc fdesc, System.Int32 player_id, System.Int32 team_id)
System.Void setupFighterComponent(via.GameObject fighter, app.battle.FighterDesc fdesc, System.Int32 player_id, System.Int32 team_id)
app.battle.FighterDesc findFighterDesc(System.Int32 player_id)
System.Void clearFighterResource(System.Int32 player_id)
System.Void clearFighterComponent(app.battle.FighterDesc fdesc)
System.Void clearFighterComponentWTTeam(app.battle.FighterDesc fdesc)
System.Boolean isMaterialReady()
System.Void updateBattlePause()
System.Void updateFighterPause()
System.Void onCreatedAkebono(via.effect.script.CreatedEffectContainer.doSomethingRelevantParam param)
System.Void updateAkebono()
System.Void updateEffectLimitNum()
System.Boolean shouldEffectLimitNum(nAction.FVfxRequest req)
System.Boolean hasCreatedEffect(nAction.FVfxRequest req)
System.Int32 getEffectLimitNum(app.vfx.VfxID id)
System.Void setDisplayStage(System.Boolean enable)
System.Void setForceStartFlag(System.Boolean start_flag)
System.Void updateRollbackCount()
static System.Boolean <onLoadCustomizeData>g__GetSkillIds|152_0(System.Int32 teamID, System.Collections.Generic.List`1<System.UInt32> skillIDs, app.battle.uBattleCore.<>c__DisplayClass152_0 )

8:15:34 PM · describe app.PlayerBehavior

app.PlayerBehavior : via.Behavior

fields
app.PlayerColorController _ColorCtrl
app.vfx.VfxActorEffectManager mpVfxMng
app.vfx.VfxExternParamManager mpVfxExternMng
app.bPostProcessController mpPPCtrl
System.Boolean IsStopPrev
System.Collections.Generic.List`1<nAction.FLocalVfxRequest> VfxPrevRangeRequest
System.Collections.Generic.List`1<nAction.FVfxRequest> VfxExternalRequest
via.GameObject Target
app.FacialParam FCEParam
static System.UInt32[] UI_HashTbl
static System.UInt32[] MatHashTbl
static System.UInt32[] HitHashTbl
via.motion.Motion mpMot
via.motion.Motion mpFace
app.esports.PBFacial _Facial
System.Int32 ActSetCount
System.UInt32 PreMotUniqueID
System.UInt32 PreBlendUniqueID
System.Boolean PreMirror
System.Boolean InnerMirror
System.Boolean IsChangeMotion
System.Boolean IsMirrorSide
System.Boolean IsMirrorMot
System.Boolean Blend180
System.UInt32 HashRoot
System.Boolean IsLocked
System.Boolean TargetAction
System.Boolean IsUseLower
System.Boolean DisableLower
System.Boolean CommonMotion
static System.Int32 MAIN
static System.Int32 BLE0
static System.Int32 BLE1
static System.Int32 MOT_BUFF_NUM
System.Int32[] MotPtr
System.Boolean[] MotActive
System.Single[] BleRate
System.Single[] BleRateL
CharacterAsset.EMergeType MergeType
CharacterAsset.EMergeType PreMergeType
static System.UInt32 SizeHash
via.userdata.VariableUintHandle SizeHandle
static System.UInt32 FreeHash
via.userdata.VariableUintHandle FreeHandle
static System.UInt32 BondHash
via.userdata.VariableSingleHandle BondHandle
static via.Quaternion quat180
via.Quaternion Dst_Hip
via.Quaternion Src_Hip
System.Single PrevRot
System.Single AccRot
System.Single InvRetargetWaistRatio
System.Single WaistRatio
System.Single HeightRatio
System.Collections.Generic.List`1<via.Joint> AntiBlendJoint
static System.Int32 MOTION_BLEND_INFO_MAX
static System.Single COMN_HEIGHT
static System.UInt32 HASH_CMN
System.Collections.Generic.List`1<via.motion.MotionBankResourceHolder> BBankHolderALL
System.Collections.Generic.List`1<via.motion.MotionBankResourceHolder> FBankHolderALL
System.Collections.Generic.List`1<via.motion.DynamicMotionBank> BMotBankList
System.Collections.Generic.List`1<via.motion.DynamicMotionBank> FMotBankList
System.Collections.Generic.List`1<System.UInt32> BBankBankIdALL
System.Collections.Generic.List`1<System.UInt32> FBankBankIdALL
System.Boolean IsResetPhysics
System.Boolean IsFreezePhysics
System.Boolean IsResetHavok
System.Boolean IsReqResetHavok
System.UInt32 HavokStabilizeNum
app.AvatarWindController mpWindCtrl
app.FGClipSlowController mpSlowController
app.esports.MuscleControl _MuscleControl
System.Collections.Generic.List`1<via.havok.HavokCloth> _HavokClothList
app.WrinkleControl _WrinkleControl
via.motion.Chain[] mChainList
app.FGClipSlowController _mFgClipSlowController
System.Collections.Generic.List`1<app.PlayerBehavior.TempMaterialFloatData> _TempMaterialFloatDatas
app.esports.BattleTimeLineMaterialController _MaterialController
System.Int32 _PlayerID
System.Single <BattleFrame>k__BackingField
System.Single <GroundY>k__BackingField
System.Single <CeilingY>k__BackingField
System.Single CeilingCoeffDeltaY
System.Boolean IsLanding
via.vec2 SearchTerrainDistance
System.Boolean _IsCeiling
System.Single _CeilingMarginDistance
System.Boolean _IsCalcCeilingY
System.Collections.Generic.List`1<via.render.Mesh> mpMeshes
System.Collections.Generic.List`1<via.render.Mesh> mpExtraBodyMeshes
app.PBFacialLookAt LookAtController
System.Collections.Generic.List`1<app.CharacterLightBehavior> mpCharaLights
app.esports.PlayerBehaviorManager _PBManager
app.SmallDamageNudgeController _NudgeCtrl
app.SmallDamageExpressionInfo SmallDamageNudgeData
via.motion.IkBodyRigResourceHolder IkBodyRigResource
app.esports.PBDamageExpression _Damage
app.PlayerBehavior.AddBlendInterpolation _AddBlendInterp
System.Boolean IsApplyResource
System.Boolean <IsAppliedResource>k__BackingField
static System.Boolean isMeshRef
via.GameObjectRef _BodyObjRef
via.GameObjectRef _HeadObjRef
via.GameObjectRef _HairObjRef
via.GameObjectRef _BoneObjRef
static System.Boolean IkCollectionParam
app.battle.PBIk _PBIk
via.Component[] StopComponentsByRollback

methods
app.PlayerColorController get_ColorCtrl()
System.Void set_ColorCtrl(app.PlayerColorController value)
System.Void SetupColor()
System.Void SetupMaterialColor()
System.Void SetupCharacterMeshColor(System.Int32 ColorNo)
app.vfx.VfxActorEffectManager GetVfxManager()
via.vec3 get_TargetPosition()
System.Void SetupEffect()
System.Void SetupVfxManager()
System.Void DestroyEffect()
System.Void updateEffect()
System.Void CheckVfx(nAction.FVfxRequest req, app.FPlayerInfo pl_inf, System.Boolean isForce)
System.Void updateTargetObject(app.FPlayerInfo pl_inf)
System.Void requestEffect(nAction.FVfxRequest req, via.GameObject owner, app.vfx.VfxActorEffectManager vfxmng)
System.Void execRequestAll(System.Action`1<app.vfx.VfxActorEffectManager> act, System.Boolean activeProjOnly)
System.Boolean isRangeStart(nAction.FVfxRequest req)
System.Boolean isRangeEnd(nAction.FVfxRequest req)
System.Void setTargetDistanceVariables(System.Collections.Generic.List`1<via.userdata.Variable> vars)
System.Void setMirrorVariables(System.Collections.Generic.List`1<via.userdata.Variable> vars)
System.Void setStencilIDVariables(System.Collections.Generic.List`1<via.userdata.Variable> vars)
System.Void setProjectileDistanceVariables(System.Collections.Generic.List`1<via.userdata.Variable> vars)
System.Void RollBack(System.Int32 rollBackFrame)
System.Void ClearVfxPrevRangeList()
System.Int32 get_MotPtrMain()
System.Void set_MotPtrMain(System.Int32 value)
System.Int32 get_MotPtrBle0()
System.Void set_MotPtrBle0(System.Int32 value)
System.Int32 get_MotPtrBle1()
System.Void set_MotPtrBle1(System.Int32 value)
System.Int32 get_MotPtrMainL()
System.Int32 get_MotPtrBle0L()
System.Int32 get_MotPtrBle1L()
System.Boolean get_MotActiveMain()
System.Void set_MotActiveMain(System.Boolean value)
System.Boolean get_MotActiveBle0()
System.Void set_MotActiveBle0(System.Boolean value)
System.Boolean get_MotActiveBle1()
System.Void set_MotActiveBle1(System.Boolean value)
System.Single get_BleRateMain()
System.Void set_BleRateMain(System.Single value)
System.Single get_BleRateBle0()
System.Void set_BleRateBle0(System.Single value)
System.Single get_BleRateBle1()
System.Void set_BleRateBle1(System.Single value)
System.Single get_BleRateMainL()
System.Void set_BleRateMainL(System.Single value)
System.Single get_BleRateBle0L()
System.Void set_BleRateBle0L(System.Single value)
System.Single get_BleRateBle1L()
System.Void set_BleRateBle1L(System.Single value)
System.Boolean get_IsMirror()
System.Boolean get_IsInnerMirror()
System.Boolean get_IsTargetAction()
System.Boolean get_IsCommonMotion()
System.Boolean IsWaitBlend()
via.motion.Motion get_MotComp()
app.esports.PBFacial get_Facial()
System.Void SetMotPtr(System.Int32[] from)
System.Void SetMotActive(System.Boolean[] from)
System.Void SetBleRate(System.Single[] from)
System.Void SetBleRateL(System.Single[] from)
System.Void SetMergeType(CharacterAsset.EMergeType from)
System.Int32[] GetMotPtr()
System.Boolean[] GetMotActive()
System.Single[] GetBleRate()
System.Single[] GetBleRateL()
CharacterAsset.EMergeType GetMergeType()
System.Void OnPlaySoundCallFacial(System.UInt32 hash)
System.Void DestroyMotion()
System.Void SetupMotion()
System.Void SetupFaceMotion()
System.Void SetupJointMap()
System.Void SetupJointHash()
System.Void SetupWaistRatio()
System.Void SetupUserVariables()
System.Void UpdateJointPosUI()
System.Void UpdateMotion()
static System.Int32 LayerPtrAdd(System.Int32 before, System.Int32 add)
System.Void updateExtensionMotion()
System.Void lateUpdateMotion()
System.Void LockCheck(System.Boolean isTarget)
System.Void callback_LayerUpdatedEvent(via.motion.Motion pMot, via.motion.TreeLayer pLayer)
System.Void ReverseLayerRT(via.motion.TreeLayer motLayer, System.UInt32 NameHash)
System.Void WaistHeight(via.motion.TreeLayer motLayer)
System.Void CancelBodyScale(via.motion.TreeLayer motLayer)
System.Void WaistRevise(via.motion.TreeLayer motLayer)
System.Void CancelPartsHokan()
via.vec3 GetJointPos(System.UInt32 hash, System.Boolean isMirror)
System.Void DestroyMotionBankBody()
System.Void DestroyMotionBankFace()
System.Void SetupMotionBankBody()
System.Void SetupMotionBankFace()
System.Void ActivateThrowBankBody(via.motion.Motion targetComp)
System.Void ActivateThrowBankFace(via.motion.Motion targetFace)
System.Void CreateDynamicMotBank(via.motion.DynamicMotionBank dstBank, via.motion.DynamicMotionBank srcBank, System.Int32 newOrder, System.Int32 bankType)
System.Void ResetPhysicsReq(System.Boolean isResetHavok, System.Boolean isReqResetHavok, System.UInt32 stabilizeNum)
System.Void ResetPhysics()
System.Void ResetHavoks()
System.Void FreezePhysicsReq()
System.Void FreezePhysics()
System.Void FreezePhysics_Force()
System.Void SetupJointConstraints(via.GameObject childObj, app.battle.assets.FighterVisualHolder.PartsType partsType, app.battle.assets.JointConstraintsData jcsData)
System.Void SetupChainDatas(via.GameObject childObj, app.battle.assets.FighterVisualHolder.PartsType partsType, app.battle.assets.ChainData chainData)
System.Void setup_chain(via.GameObject _childObj, app.battle.assets.FighterVisualHolder.PartsType _partsType, app.battle.assets.ChainData _chainData, via.motion.Chain _chain, via.motion.ChildSecondary _secondary, via.motion.Motion _motion)
System.Void SetupAOGeometryData(via.GameObject childObj, app.battle.assets.FighterVisualHolder.PartsType partsType, app.battle.assets.AOGeometryData aoGeometryData)
System.Void SetupHavokClothData(via.GameObject childObj, app.battle.assets.FighterVisualHolder.PartsType partsType, app.battle.assets.HavokClothData havokClothData)
System.Void SetShaderTimerIndex()
System.Void ResetShaderTimerIndex()
System.Void resetSmallDamageIndex()
app.esports.MuscleControl get_MuscleControl()
System.Collections.Generic.List`1<via.havok.HavokCloth> get_HavokClothList()
System.Void setupTimeline()
System.Void SetupBattleTimelineForParts(app.PartsBehavior pb)
System.Void .ctor()
System.Void onDestroy()
System.Void awake()
System.Void onUnload()
System.Void start()
System.Void update()
System.Void lateUpdate()
System.Void UpdateGroundMaterial()
app.esports.PlayerBehaviorManager get_PBManager()
System.Void set_PBManager(app.esports.PlayerBehaviorManager value)
System.Int32 get_PlayerID()
System.Void set_PlayerID(System.Int32 value)
System.Void ReleaseConnection(System.Boolean toLoserCtrl)
System.Void SetupCharacterLight()
System.Void UpdateMesh()
System.Void SetupAppearance()
System.Void UpdatePosition(app.FPlayerInfo pl_inf)
System.Void UpdateComponentEnableByRollback()
System.Void UpdateComponentEnabled(System.Boolean enabled)
System.Void GetStopComponentsByRollback()
System.Single get_BattleFrame()
System.Void set_BattleFrame(System.Single value)
System.Single get_GroundY()
System.Void set_GroundY(System.Single value)
System.Single get_CeilingY()
System.Void set_CeilingY(System.Single value)
System.Boolean get_IsCeiling()
System.Void SetLanding(System.Boolean enable, via.vec2 search_dist)
System.Void SetCeiling(System.Boolean enable, System.Single dist, System.Boolean is_use_ceiling_y, System.Single ceiling_y)
System.Boolean GetLanding()
System.Void AddExtraBodyMehes(via.render.Mesh mesh)
System.Void RemoveExtraBodyMeshes(via.render.Mesh mesh)
System.Void set_BattleLookData(app.BattleLookAtData value)
app.esports.PBDamageExpression get_Damage()
System.Void set_IsAppliedResource(System.Boolean value)
System.Boolean get_IsAppliedResource()
System.Collections.Generic.Dictionary`2<app.battle.assets.FighterVisualHolder.PartsType,via.GameObjectRef> get_GetGameObjectRefList()
via.GameObjectRef get_BodyObjRef()
System.Void set_BodyObjRef(via.GameObjectRef value)
via.GameObjectRef get_HeadObjRef()
System.Void set_HeadObjRef(via.GameObjectRef value)
System.Void SetHeadObject(via.GameObject headObject)
System.Void SetBodyObject(via.GameObject bodyObject)
System.Void SetHairObject(via.GameObject hairObject)
via.GameObjectRef get_HairObjRef()
System.Void set_HairObjRef(via.GameObjectRef value)
via.GameObjectRef get_BoneObjRef()
System.Void set_BoneObjRef(via.GameObjectRef value)
app.battle.PBIk get_PBIK()
System.Boolean get_IsUsePBIkPhyCoeffLeg()
System.Void set_IsUsePBIkPhyCoeffLeg(System.Boolean value)
static System.Void .cctor()
System.Boolean <UpdateMotion>g__CheckChangeMotion|158_0(app.PlayerBehavior.<>c__DisplayClass158_0 )
System.Boolean <UpdateMotion>g___IsSamePose|158_1(System.Int32 buff_index, app.PlayerBehavior.<>c__DisplayClass158_0 )
System.Boolean <UpdateMotion>g___IsToWaitBlendEnd|158_2(app.PlayerBehavior.<>c__DisplayClass158_0 )
System.Boolean <UpdateMotion>g___IsToWaitBlendStart|158_3(app.PlayerBehavior.<>c__DisplayClass158_0 )
System.Void <callback_LayerUpdatedEvent>g__getMotLayerIndex|163_0(System.UInt32 no, System.Int32 layer, System.Int32 layer_l)
System.Void <WaistRevise>g___ReverseFuncRT|168_0(System.UInt32 NameHash, app.PlayerBehavior.<>c__DisplayClass168_0 )
static System.Void <CancelPartsHokan>g___HokanCancel|169_0(via.motion.TreeLayer motLayer, app.PlayerBehavior.<>c__DisplayClass169_0 )
System.Void <update>b__225_0()
System.Void <update>b__225_1()
System.Void <update>b__225_2()
System.Void <update>b__225_3()
System.Void <update>b__225_4()
System.Void <update>b__225_5()
System.Void <lateUpdate>b__226_0()
System.Void <lateUpdate>b__226_1()
System.Void <lateUpdate>b__226_2()

8:15:34 PM · _PlayerBehaviors

{"array":"app.PlayerBehavior[]","element":"app.PlayerBehavior","length":6}```
