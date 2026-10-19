# Training types — SF6 Steam, REFramework v1.5.9.1, TDB 71, 2026-10-19

Output of the dev page's "Describe training types" (object.describe on live objects). Static fields show offset 16 because the plugin reports instance offsets only.

```
describe RecordData

app.training.TrainingData.TM_RecordSetting.RecordData : System.Object size 48

fields
System.Boolean IsForceStop @16
System.Int32 State @20
System.Int32 Cursor @24
System.Boolean isLoop @28
System.UInt16[] buff @32
System.Int32 Num @40
System.SByte cmd_type @44
System.Boolean negativeEdge @45

methods
System.Void .ctor()
System.Void Reset()
System.Void DeepCopy(app.training.TrainingData.TM_RecordSetting.RecordData)
System.Void DeepCopy(app.TrainingInput.Record)
static app.TrainingInput.Record op_Implicit(app.training.TrainingData.TM_RecordSetting.RecordData)

describe SlotData

app.training.TrainingData.TM_RecordSetting.SlotData : System.Object size 56

fields
System.Boolean IsActive @16
System.Boolean IsValid @17
System.Int32 Weight @20
System.Int32 Frame @24
System.Guid Title @32
app.training.TrainingData.TM_RecordSetting.RecordData InputData @48

methods
System.Void .ctor()
System.Void Init()
System.Void DeepCopy(app.training.TrainingData.TM_RecordSetting.SlotData)

describe FighterData

app.training.TrainingData.TM_RecordSetting.FighterData : System.Object size 32

fields
System.Int32 FighterID @16
app.training.TrainingData.TM_RecordSetting.SlotData[] RecordSlots @24

methods
System.Void .ctor()
System.Void Init()
System.Void DeepCopy(app.training.TrainingData.TM_RecordSetting.FighterData)
System.Boolean IsActiveAnyone()

describe FighterDataList

System.Collections.Generic.List`1<app.training.TrainingData.TM_RecordSetting.FighterData> : System.Object size 32

fields
static System.Int32 DefaultCapacity @16
app.training.TrainingData.TM_RecordSetting.FighterData[] _items @16
System.Int32 _size @24
System.Int32 _version @28
static app.training.TrainingData.TM_RecordSetting.FighterData[] s_emptyArray @16

methods
System.Void .ctor()
System.Void .ctor(System.Int32)
System.Void .ctor(System.Collections.Generic.IEnumerable`1<app.training.TrainingData.TM_RecordSetting.FighterData>)
System.Int32 get_Capacity()
System.Void set_Capacity(System.Int32)
System.Int32 get_Count()
System.Boolean System.Collections.IList.get_IsFixedSize()
System.Boolean System.Collections.Generic.ICollection<T>.get_IsReadOnly()
System.Boolean System.Collections.IList.get_IsReadOnly()
System.Boolean System.Collections.ICollection.get_IsSynchronized()
System.Object System.Collections.ICollection.get_SyncRoot()
app.training.TrainingData.TM_RecordSetting.FighterData get_Item(System.Int32)
System.Void set_Item(System.Int32, app.training.TrainingData.TM_RecordSetting.FighterData)
static System.Boolean IsCompatibleObject(System.Object)
System.Object System.Collections.IList.get_Item(System.Int32)
System.Void System.Collections.IList.set_Item(System.Int32, System.Object)
System.Void Add(app.training.TrainingData.TM_RecordSetting.FighterData)
System.Void AddWithResize(app.training.TrainingData.TM_RecordSetting.FighterData)
System.Int32 System.Collections.IList.Add(System.Object)
System.Void AddRange(System.Collections.Generic.IEnumerable`1<app.training.TrainingData.TM_RecordSetting.FighterData>)
System.Collections.ObjectModel.ReadOnlyCollection`1<app.training.TrainingData.TM_RecordSetting.FighterData> AsReadOnly()
System.Int32 BinarySearch(System.Int32, System.Int32, app.training.TrainingData.TM_RecordSetting.FighterData, System.Collections.Generic.IComparer`1<app.training.TrainingData.TM_RecordSetting.FighterData>)
System.Int32 BinarySearch(app.training.TrainingData.TM_RecordSetting.FighterData)
System.Int32 BinarySearch(app.training.TrainingData.TM_RecordSetting.FighterData, System.Collections.Generic.IComparer`1<app.training.TrainingData.TM_RecordSetting.FighterData>)
System.Void Clear()
System.Boolean Contains(app.training.TrainingData.TM_RecordSetting.FighterData)
System.Boolean System.Collections.IList.Contains(System.Object)
System.Collections.Generic.List`1<!!0> ConvertAll(System.Converter`2<app.training.TrainingData.TM_RecordSetting.FighterData,!!0>)
System.Void CopyTo(app.training.TrainingData.TM_RecordSetting.FighterData[])
System.Void System.Collections.ICollection.CopyTo(System.Array, System.Int32)
System.Void CopyTo(System.Int32, app.training.TrainingData.TM_RecordSetting.FighterData[], System.Int32, System.Int32)
System.Void CopyTo(app.training.TrainingData.TM_RecordSetting.FighterData[], System.Int32)
System.Void EnsureCapacity(System.Int32)
System.Boolean Exists(System.Predicate`1<app.training.TrainingData.TM_RecordSetting.FighterData>)
app.training.TrainingData.TM_RecordSetting.FighterData Find(System.Predicate`1<app.training.TrainingData.TM_RecordSetting.FighterData>)
System.Collections.Generic.List`1<app.training.TrainingData.TM_RecordSetting.FighterData> FindAll(System.Predicate`1<app.training.TrainingData.TM_RecordSetting.FighterData>)
System.Int32 FindIndex(System.Predicate`1<app.training.TrainingData.TM_RecordSetting.FighterData>)
System.Int32 FindIndex(System.Int32, System.Predicate`1<app.training.TrainingData.TM_RecordSetting.FighterData>)
System.Int32 FindIndex(System.Int32, System.Int32, System.Predicate`1<app.training.TrainingData.TM_RecordSetting.FighterData>)
app.training.TrainingData.TM_RecordSetting.FighterData FindLast(System.Predicate`1<app.training.TrainingData.TM_RecordSetting.FighterData>)
System.Int32 FindLastIndex(System.Predicate`1<app.training.TrainingData.TM_RecordSetting.FighterData>)
System.Int32 FindLastIndex(System.Int32, System.Predicate`1<app.training.TrainingData.TM_RecordSetting.FighterData>)
System.Int32 FindLastIndex(System.Int32, System.Int32, System.Predicate`1<app.training.TrainingData.TM_RecordSetting.FighterData>)
System.Void ForEach(System.Action`1<app.training.TrainingData.TM_RecordSetting.FighterData>)
System.Collections.Generic.List`1.Enumerator<app.training.TrainingData.TM_RecordSetting.FighterData> GetEnumerator()
System.Collections.Generic.IEnumerator`1<app.training.TrainingData.TM_RecordSetting.FighterData> System.Collections.Generic.IEnumerable<T>.GetEnumerator()
System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator()
System.Collections.Generic.List`1<app.training.TrainingData.TM_RecordSetting.FighterData> GetRange(System.Int32, System.Int32)
System.Int32 IndexOf(app.training.TrainingData.TM_RecordSetting.FighterData)
System.Int32 System.Collections.IList.IndexOf(System.Object)
System.Int32 IndexOf(app.training.TrainingData.TM_RecordSetting.FighterData, System.Int32)
System.Int32 IndexOf(app.training.TrainingData.TM_RecordSetting.FighterData, System.Int32, System.Int32)
System.Void Insert(System.Int32, app.training.TrainingData.TM_RecordSetting.FighterData)
System.Void System.Collections.IList.Insert(System.Int32, System.Object)
System.Void InsertRange(System.Int32, System.Collections.Generic.IEnumerable`1<app.training.TrainingData.TM_RecordSetting.FighterData>)
System.Int32 LastIndexOf(app.training.TrainingData.TM_RecordSetting.FighterData)
System.Int32 LastIndexOf(app.training.TrainingData.TM_RecordSetting.FighterData, System.Int32)
System.Int32 LastIndexOf(app.training.TrainingData.TM_RecordSetting.FighterData, System.Int32, System.Int32)
System.Boolean Remove(app.training.TrainingData.TM_RecordSetting.FighterData)
System.Void System.Collections.IList.Remove(System.Object)
System.Int32 RemoveAll(System.Predicate`1<app.training.TrainingData.TM_RecordSetting.FighterData>)
System.Void RemoveAt(System.Int32)
System.Void RemoveRange(System.Int32, System.Int32)
System.Void Reverse()
System.Void Reverse(System.Int32, System.Int32)
System.Void Sort()
System.Void Sort(System.Collections.Generic.IComparer`1<app.training.TrainingData.TM_RecordSetting.FighterData>)
System.Void Sort(System.Int32, System.Int32, System.Collections.Generic.IComparer`1<app.training.TrainingData.TM_RecordSetting.FighterData>)
System.Void Sort(System.Comparison`1<app.training.TrainingData.TM_RecordSetting.FighterData>)
app.training.TrainingData.TM_RecordSetting.FighterData[] ToArray()
System.Void TrimExcess()
System.Boolean TrueForAll(System.Predicate`1<app.training.TrainingData.TM_RecordSetting.FighterData>)
static System.Void .cctor()

describe RecordSetting

app.training.TrainingData.TM_RecordSetting : System.Object size 48

fields
app.training.RECORD_TYPE RecordType @16
app.training.RECORD_START_TYPE RecordStartType @20
app.training.RECORD_COUNTDOWN RecordCountDown @24
app.training.PLAY_TYPE PlayType @28
app.training.RECORD_INFO_TYPE InfoType @32
app.training.PLAY_LOOP_TYPE LoopType @36
System.Collections.Generic.List`1<app.training.TrainingData.TM_RecordSetting.FighterData> FighterDataList @40

methods
System.Void .ctor()
System.Void Init()
System.Void DeepCopy(app.training.TrainingData.TM_RecordSetting)
System.Int32 GetFighterIndex(System.Int32)
System.Boolean IsValidFighterID(System.Int32)
System.Void Update(app.training.TrainingData.TM_RecordSetting)
System.Void RemoveFighterRecords(app.training.TrainingData.TM_RecordSetting)
System.Void AddFighterRecords(app.training.TrainingData.TM_RecordSetting)
System.Boolean get_IsLoop()

describe TrainingData

app.training.TrainingData : app.storage.SaveDataBase size 144

fields
static System.Int32 TRAINING_PLAYER_COUNT @16
static System.Int32 FIGHTER_NUM @16
static System.Int32 SHORT_CUT_DATA_NUM @16
static System.Int32 PLAYER_ID @16
static System.Int32 DUMMY_PLAYER_ID @16
static System.Int32 RECORD_MAX @16
app.training.TrainingData.TM_SelectMenu SelectMenu @24
app.training.TrainingData.TM_DummyStatus DummyStatus @32
app.training.TrainingData.TM_GuardSetting GuardSetting @40
app.training.TrainingData.TM_DefenseSystem DefenseSystem @48
app.training.TrainingData.TM_CounterSetting CounterSetting @56
app.training.TrainingData.TM_ParameterSetting ParameterSetting @64
app.training.TrainingData.TM_DisplaySetting DisplaySetting @72
app.training.TrainingData.TM_OtherSetting OtherSetting @80
app.training.TrainingData.TM_ReversalSetting ReversalSetting @88
app.training.TrainingData.TM_ShortCutSetting ShortCutSetting @96
app.training.TrainingData.TM_RecordSetting RecordSetting @104
System.Int32 SelectIndex @112
System.Int32 SelectChildIndex @116
System.UInt32 SaveCount @120
app.AvatarRoomTrainingFighterInfoSaveData NpcFighterInfo @128
app.training.TrainingData.TM_TempData TempData @136

methods
app.storage.SaveDataBase Duplicate()
System.Void DeepCopy(app.training.TrainingData, System.UInt32)
System.Void Reset(System.Boolean, System.Boolean)
System.Void Update(app.training.TrainingData)
System.Void RemoveFighterSettingData(app.training.TrainingData)
System.Void AddFighterSettingData(app.training.TrainingData)
System.Void .ctor()
System.Void .ctor(app.training.TrainingData)
System.Void SetTabIndex(System.Int32)
System.Void SetChildIndex(System.Int32)```
