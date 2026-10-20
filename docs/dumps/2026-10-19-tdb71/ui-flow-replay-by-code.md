# Replay-by-code UI flow classes (2026-10-19, TDB 71)

Raw op console `type.find` + `object.describe`, in three batches. The in-game flow is: search by code → result list → click one result (popup) → watch replay. Leads marked in FINDINGS.

## Batch 1: result screen param, paging enum, replay info popup
```
8:48:57 PM · object.describe

{
  "fields": [
    {
      "name": "MAX_ROUND_NUM",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    }
  ],
  "methods": [
    {
      "name": "Start",
      "params": [
        {
          "name": "param",
          "type": "app.UICFNReplayInfo.FlowParam"
        }
      ],
      "returns": "app.IUIFlowHandle",
      "static": true
    },
    {
      "name": ".ctor",
      "params": [],
      "returns": "System.Void",
      "static": false
    }
  ],
  "parent": "System.Object",
  "size": 16,
  "type": "app.UICFNReplayInfo",
  "valuetype": false
}

8:48:45 PM · type.find

{
  "h": 4,
  "static": true,
  "type": "app.UICFNReplayInfo"
}

8:48:25 PM · object.describe

{
  "fields": [
    {
      "name": "<ApiFighterShortId>k__BackingField",
      "offset": 248,
      "static": false,
      "type": "System.UInt32"
    },
    {
      "name": "<BannerInfo>k__BackingField",
      "offset": 256,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Component.CommonFighterBannerInfo"
    },
    {
      "name": "_SharingData",
      "offset": 264,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Component.CommonReplayInfo"
    }
  ],
  "methods": [
    {
      "name": "get_ApiFighterShortId",
      "params": [],
      "returns": "System.UInt32",
      "static": false
    },
    {
      "name": "set_ApiFighterShortId",
      "params": [
        {
          "name": "value",
          "type": "System.UInt32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "GetApiFighterShortId",
      "params": [],
      "returns": "System.UInt32",
      "static": false
    },
    {
      "name": "get_BannerInfo",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Component.CommonFighterBannerInfo",
      "static": false
    },
    {
      "name": "set_BannerInfo",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Component.CommonFighterBannerInfo"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "GetApiFighterInfo",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Component.CommonFighterBannerInfo",
      "static": false
    },
    {
      "name": "GetSelectReplayInfoList",
      "params": [],
      "returns": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonReplayInfo>",
      "static": false
    },
    {
      "name": "get_ReplayId",
      "params": [],
      "returns": "System.String",
      "static": false
    },
    {
      "name": "get_IsDailyTournament",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "GetPersonalInfoSettingType",
      "params": [],
      "returns": "app.Option.PersonalInfoSettingType",
      "static": false
    },
    {
      "name": ".ctor",
      "params": [
        {
          "name": "data",
          "type": "app.network.api.HatoClientAPI.Component.CommonReplayInfo"
        },
        {
          "name": "isAllView",
          "type": "System.Boolean"
        },
        {
          "name": "isResultDisp",
          "type": "System.Boolean"
        },
        {
          "name": "isReplayViewEnable",
          "type": "System.Boolean"
        },
        {
          "name": "replayViewEvent",
          "type": "System.Action"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "UpdateDispItem",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "MenuDecideEvent",
      "params": [
        {
          "name": "flow",
          "type": "app.UIFlowBase"
        },
        {
          "name": "decideMenuType",
          "type": "app.UICFNReplayInfo.MenuType"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<UpdateDispItem>g__updateMenuItem|18_0",
      "params": [],
      "returns": "System.Void",
      "static": false
    }
  ],
  "parent": "app.UICFNReplayInfo.FlowParamBase",
  "size": 272,
  "type": "app.UICFNReplayInfo.FlowParam",
  "valuetype": false
}

8:48:12 PM · type.find

{
  "h": 3,
  "static": true,
  "type": "app.UICFNReplayInfo.FlowParam"
}

8:47:52 PM · field.get

3

8:47:46 PM · field.get

2

8:47:40 PM · field.get

1

8:47:34 PM · field.get

0

8:47:08 PM · object.describe

{
  "fields": [
    {
      "name": "value__",
      "offset": 16,
      "static": false,
      "type": "System.Int32"
    },
    {
      "name": "NONE",
      "offset": 16,
      "static": true,
      "type": "app.UICFNReplaySearchResult.CallSearchResultType"
    },
    {
      "name": "SORT",
      "offset": 16,
      "static": true,
      "type": "app.UICFNReplaySearchResult.CallSearchResultType"
    },
    {
      "name": "PAGE_PREV",
      "offset": 16,
      "static": true,
      "type": "app.UICFNReplaySearchResult.CallSearchResultType"
    },
    {
      "name": "PAGE_NEXT",
      "offset": 16,
      "static": true,
      "type": "app.UICFNReplaySearchResult.CallSearchResultType"
    }
  ],
  "methods": [],
  "parent": "System.Enum",
  "size": 20,
  "type": "app.UICFNReplaySearchResult.CallSearchResultType",
  "valuetype": true
}

8:46:40 PM · type.find

{
  "h": 2,
  "static": true,
  "type": "app.UICFNReplaySearchResult.CallSearchResultType"
}

8:46:24 PM · object.describe

{
  "fields": [
    {
      "name": "<SharingData>k__BackingField",
      "offset": 112,
      "static": false,
      "type": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonReplayInfo>"
    },
    {
      "name": "<TopTemporaryData>k__BackingField",
      "offset": 120,
      "static": false,
      "type": "app.UICFNReplayTop.TopTemporaryData"
    },
    {
      "name": "<MyFlowHandle>k__BackingField",
      "offset": 128,
      "static": false,
      "type": "app.IUIFlowHandle"
    },
    {
      "name": "<IsRestore>k__BackingField",
      "offset": 136,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "<IsSaveRestore>k__BackingField",
      "offset": 137,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "<CallSearchResultType>k__BackingField",
      "offset": 140,
      "static": false,
      "type": "app.UICFNReplaySearchResult.CallSearchResultType"
    },
    {
      "name": "<IsLimitUpper>k__BackingField",
      "offset": 144,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "<IsLimitLower>k__BackingField",
      "offset": 145,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "<IsDetailedSort>k__BackingField",
      "offset": 146,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "_RootGroup",
      "offset": 152,
      "static": false,
      "type": "app.UIPartsGroup"
    },
    {
      "name": "_CFNSortButton",
      "offset": 160,
      "static": false,
      "type": "app.UIPartsCFNSortButton"
    },
    {
      "name": "_ReplayList",
      "offset": 168,
      "static": false,
      "type": "app.UIPartsReplayList"
    }
  ],
  "methods": [
    {
      "name": "get_SharingData",
      "params": [],
      "returns": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonReplayInfo>",
      "static": false
    },
    {
      "name": "set_SharingData",
      "params": [
        {
          "name": "value",
          "type": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonReplayInfo>"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_TopTemporaryData",
      "params": [],
      "returns": "app.UICFNReplayTop.TopTemporaryData",
      "static": false
    },
    {
      "name": "set_TopTemporaryData",
      "params": [
        {
          "name": "value",
          "type": "app.UICFNReplayTop.TopTemporaryData"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_FocusInfo",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Component.CommonReplayInfo",
      "static": false
    },
    {
      "name": "get_IsMultiSelectMode",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "get_MyFlowHandle",
      "params": [],
      "returns": "app.IUIFlowHandle",
      "static": false
    },
    {
      "name": "set_MyFlowHandle",
      "params": [
        {
          "name": "value",
          "type": "app.IUIFlowHandle"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_ControlType",
      "params": [],
      "returns": "app.UICFNReplaySearchResult.ControlType",
      "static": false
    },
    {
      "name": "set_ControlType",
      "params": [
        {
          "name": "value",
          "type": "app.UICFNReplaySearchResult.ControlType"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_IsRestore",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "set_IsRestore",
      "params": [
        {
          "name": "value",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_IsSaveRestore",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "set_IsSaveRestore",
      "params": [
        {
          "name": "value",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_CallSearchResultType",
      "params": [],
      "returns": "app.UICFNReplaySearchResult.CallSearchResultType",
      "static": false
    },
    {
      "name": "set_CallSearchResultType",
      "params": [
        {
          "name": "value",
          "type": "app.UICFNReplaySearchResult.CallSearchResultType"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_IsLimitUpper",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "set_IsLimitUpper",
      "params": [
        {
          "name": "value",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_IsLimitLower",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "set_IsLimitLower",
      "params": [
        {
          "name": "value",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_IsDetailedSort",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "set_IsDetailedSort",
      "params": [
        {
          "name": "value",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": ".ctor",
      "params": [
        {
          "name": "data",
          "type": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonReplayInfo>"
        },
        {
          "name": "topTemporaryData",
          "type": "app.UICFNReplayTop.TopTemporaryData"
        },
        {
          "name": "isRestore",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_ObjectPrefabKey",
      "params": [],
      "returns": "System.String",
      "static": false
    },
    {
      "name": "CreatedObject",
      "params": [
        {
          "name": "flow",
          "type": "app.UIFlowCommon.CreateObject"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "CheckMainFlowMouseEvent",
      "params": [
        {
          "name": "flow",
          "type": "app.UIFlowBase"
        },
        {
          "name": "mouseEvent",
          "type": "app.UIMouseEvent"
        },
        {
          "name": "parts",
          "type": "app.UIPartsMouseOperable"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "ShowedObject",
      "params": [
        {
          "name": "flow",
          "type": "app.UIFlowCommon.ShowObject"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "OnEnd",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "ChangeMainFlow",
      "params": [
        {
          "name": "flow",
          "type": "app.UIFlowBase"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "ChangeDataUpdateFlow",
      "params": [
        {
          "name": "flow",
          "type": "app.UIFlowBase"
        },
        {
          "name": "type",
          "type": "app.UICFNReplaySearchResult.CallSearchResultType"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "UpdateSharingData",
      "params": [
        {
          "name": "data",
          "type": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonReplayInfo>"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "ShowInputGuide",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "HideInputGuide",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "InitDispItem",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "UpdateDispItem",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "SortMenuOpen",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "SortMenuClose",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "SortMenuDecide",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "GetSortType",
      "params": [],
      "returns": "app.network.api.Enum.ReplaySearchSortType",
      "static": false
    },
    {
      "name": "GetSortTypeDetailed",
      "params": [],
      "returns": "app.UICFNReplaySearchResult.ReplaySearchSortType",
      "static": false
    },
    {
      "name": "GetBorderReplayId",
      "params": [
        {
          "name": "type",
          "type": "app.UICFNReplaySearchResult.CallSearchResultType"
        }
      ],
      "returns": "System.String",
      "static": false
    },
    {
      "name": "StartMultiSelect",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "EndMultiSelect",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "SelectMultiSelectFocusItem",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "GetSelectReplayInfoList",
      "params": [],
      "returns": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonReplayInfo>",
      "static": false
    },
    {
      "name": "GetMultiSelectCount",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "ReplayViewEvent",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "ExectuteSort",
      "params": [
        {
          "name": "sharingData",
          "type": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonReplayInfo>"
        },
        {
          "name": "sortType",
          "type": "app.UICFNReplaySearchResult.ReplaySearchSortType"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "CompareReplayUploaded",
      "params": [
        {
          "name": "a",
          "type": "app.network.api.HatoClientAPI.Component.CommonReplayInfo"
        },
        {
          "name": "b",
          "type": "app.network.api.HatoClientAPI.Component.CommonReplayInfo"
        },
        {
          "name": "isDesc",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "<CreatedObject>g__setupParts|49_0",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "<ShowInputGuide>g__getInputGuideMessage|56_0",
      "params": [],
      "returns": "System.String",
      "static": true
    },
    {
      "name": "<ExectuteSort>b__72_0",
      "params": [
        {
          "name": "a",
          "type": "app.network.api.HatoClientAPI.Component.CommonReplayInfo"
        },
        {
          "name": "b",
          "type": "app.network.api.HatoClientAPI.Component.CommonReplayInfo"
        }
      ],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "<ExectuteSort>b__72_1",
      "params": [
        {
          "name": "a",
          "type": "app.network.api.HatoClientAPI.Component.CommonReplayInfo"
        },
        {
          "name": "b",
          "type": "app.network.api.HatoClientAPI.Component.CommonReplayInfo"
        }
      ],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "<ExectuteSort>b__72_2",
      "params": [
        {
          "name": "a",
          "type": "app.network.api.HatoClientAPI.Component.CommonReplayInfo"
        },
        {
          "name": "b",
          "type": "app.network.api.HatoClientAPI.Component.CommonReplayInfo"
        }
      ],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "<ExectuteSort>b__72_3",
      "params": [
        {
          "name": "a",
          "type": "app.network.api.HatoClientAPI.Component.CommonReplayInfo"
        },
        {
          "name": "b",
          "type": "app.network.api.HatoClientAPI.Component.CommonReplayInfo"
        }
      ],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "<ExectuteSort>b__72_4",
      "params": [
        {
          "name": "a",
          "type": "app.network.api.HatoClientAPI.Component.CommonReplayInfo"
        },
        {
          "name": "b",
          "type": "app.network.api.HatoClientAPI.Component.CommonReplayInfo"
        }
      ],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "<ExectuteSort>b__72_5",
      "params": [
        {
          "name": "a",
          "type": "app.network.api.HatoClientAPI.Component.CommonReplayInfo"
        },
        {
          "name": "b",
          "type": "app.network.api.HatoClientAPI.Component.CommonReplayInfo"
        }
      ],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "<ExectuteSort>b__72_6",
      "params": [
        {
          "name": "a",
          "type": "app.network.api.HatoClientAPI.Component.CommonReplayInfo"
        },
        {
          "name": "b",
          "type": "app.network.api.HatoClientAPI.Component.CommonReplayInfo"
        }
      ],
      "returns": "System.Int32",
      "static": false
    }
  ],
  "parent": "app.UIFlowCFNCommon.SubUIObjectParam",
  "size": 176,
  "type": "app.UICFNReplaySearchResult.FlowParam",
  "valuetype": false
}

8:46:11 PM · type.find

{
  "h": 1,
  "static": true,
  "type": "app.UICFNReplaySearchResult.FlowParam"
}```

## Batch 2: TopTemporaryData, info popup base/menu enum, SubUIObjectParam, type.search UICFNReplayTop
```
8:53:07 PM · object.describe

{
  "fields": [
    {
      "name": "TAG_SUBUI",
      "offset": 16,
      "static": true,
      "type": "System.String[]"
    },
    {
      "name": "<HandleTags>k__BackingField",
      "offset": 104,
      "static": false,
      "type": "System.String[]"
    }
  ],
  "methods": [
    {
      "name": "get_HandleTags",
      "params": [],
      "returns": "System.String[]",
      "static": false
    },
    {
      "name": "set_HandleTags",
      "params": [
        {
          "name": "value",
          "type": "System.String[]"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "ChangeSubMenuEndFlow",
      "params": [
        {
          "name": "flow",
          "type": "app.UIFlowBase"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "SetParentParam",
      "params": [
        {
          "name": "parentParam",
          "type": "app.UIFlowCFNCommon.TabItemObjectParam"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "SetParentParam",
      "params": [
        {
          "name": "parentParam",
          "type": "app.UIFlowCFNCommon.TabItemObjectParam"
        },
        {
          "name": "childParam",
          "type": "app.UIFlowCFNCommon.CFNObjectParam"
        }
      ],
      "returns": "System.Void",
      "static": true
    },
    {
      "name": ".ctor",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": ".cctor",
      "params": [],
      "returns": "System.Void",
      "static": true
    }
  ],
  "parent": "app.UIFlowCFNCommon.ParentObjectParam",
  "size": 112,
  "type": "app.UIFlowCFNCommon.SubUIObjectParam",
  "valuetype": false
}

8:53:00 PM · object.describe

{
  "fields": [
    {
      "name": "value__",
      "offset": 16,
      "static": false,
      "type": "System.Int32"
    },
    {
      "name": "REPLAY",
      "offset": 16,
      "static": true,
      "type": "app.UICFNReplayInfo.MenuType"
    },
    {
      "name": "COMMENTATOR",
      "offset": 16,
      "static": true,
      "type": "app.UICFNReplayInfo.MenuType"
    },
    {
      "name": "REGIST",
      "offset": 16,
      "static": true,
      "type": "app.UICFNReplayInfo.MenuType"
    },
    {
      "name": "UNREGIST",
      "offset": 16,
      "static": true,
      "type": "app.UICFNReplayInfo.MenuType"
    },
    {
      "name": "PROFILE1",
      "offset": 16,
      "static": true,
      "type": "app.UICFNReplayInfo.MenuType"
    },
    {
      "name": "PROFILE2",
      "offset": 16,
      "static": true,
      "type": "app.UICFNReplayInfo.MenuType"
    },
    {
      "name": "SEARCH1",
      "offset": 16,
      "static": true,
      "type": "app.UICFNReplayInfo.MenuType"
    },
    {
      "name": "SEARCH2",
      "offset": 16,
      "static": true,
      "type": "app.UICFNReplayInfo.MenuType"
    },
    {
      "name": "RESULT_LIST",
      "offset": 16,
      "static": true,
      "type": "app.UICFNReplayInfo.MenuType"
    },
    {
      "name": "NUM",
      "offset": 16,
      "static": true,
      "type": "app.UICFNReplayInfo.MenuType"
    }
  ],
  "methods": [],
  "parent": "System.Enum",
  "size": 20,
  "type": "app.UICFNReplayInfo.MenuType",
  "valuetype": true
}

8:52:58 PM · object.describe

{
  "fields": [
    {
      "name": "<IsAllView>k__BackingField",
      "offset": 112,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "<IsResultDisp>k__BackingField",
      "offset": 113,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "<IsReplayViewEnable>k__BackingField",
      "offset": 114,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "<ReplayViewEvent>k__BackingField",
      "offset": 120,
      "static": false,
      "type": "System.Action"
    },
    {
      "name": "<CommentatorSetting>k__BackingField",
      "offset": 128,
      "static": false,
      "type": "app.UIFlowCommentatorSetting"
    },
    {
      "name": "_BattleType",
      "offset": 136,
      "static": false,
      "type": "app.UIPartsReplayBattleType"
    },
    {
      "name": "_BattleModePanel",
      "offset": 144,
      "static": false,
      "type": "via.gui.Panel"
    },
    {
      "name": "_BattleModeText",
      "offset": 152,
      "static": false,
      "type": "via.gui.Text"
    },
    {
      "name": "_FavoritePanel",
      "offset": 160,
      "static": false,
      "type": "via.gui.Panel"
    },
    {
      "name": "_ReplayIdText",
      "offset": 168,
      "static": false,
      "type": "via.gui.Text"
    },
    {
      "name": "_DateText",
      "offset": 176,
      "static": false,
      "type": "via.gui.Text"
    },
    {
      "name": "_PlayCountText",
      "offset": 184,
      "static": false,
      "type": "via.gui.Text"
    },
    {
      "name": "_BattleFighterInfo_1p",
      "offset": 192,
      "static": false,
      "type": "app.UIPartsBattleFighterInfo"
    },
    {
      "name": "_BattleFighterInfo_2p",
      "offset": 200,
      "static": false,
      "type": "app.UIPartsBattleFighterInfo"
    },
    {
      "name": "_BattleRoundResult",
      "offset": 208,
      "static": false,
      "type": "app.UIPartsBattleRoundResult[]"
    },
    {
      "name": "_DetailedMenu",
      "offset": 216,
      "static": false,
      "type": "app.UIPartsCFNReplayInfoList"
    },
    {
      "name": "_BgRect",
      "offset": 224,
      "static": false,
      "type": "via.gui.Rect"
    },
    {
      "name": "_BgPanel",
      "offset": 232,
      "static": false,
      "type": "via.gui.Panel"
    },
    {
      "name": "_NotPlayPanel",
      "offset": 240,
      "static": false,
      "type": "via.gui.Panel"
    }
  ],
  "methods": [
    {
      "name": "get_IsAllView",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "set_IsAllView",
      "params": [
        {
          "name": "value",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_IsResultDisp",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "set_IsResultDisp",
      "params": [
        {
          "name": "value",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_IsReplayViewEnable",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "set_IsReplayViewEnable",
      "params": [
        {
          "name": "value",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_ReplayViewEvent",
      "params": [],
      "returns": "System.Action",
      "static": false
    },
    {
      "name": "set_ReplayViewEvent",
      "params": [
        {
          "name": "value",
          "type": "System.Action"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_CommentatorSetting",
      "params": [],
      "returns": "app.UIFlowCommentatorSetting",
      "static": false
    },
    {
      "name": "set_CommentatorSetting",
      "params": [
        {
          "name": "value",
          "type": "app.UIFlowCommentatorSetting"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_DetailedMenu",
      "params": [],
      "returns": "app.UIPartsCFNReplayInfoList",
      "static": false
    },
    {
      "name": "get_ObjectPrefabKey",
      "params": [],
      "returns": "System.String",
      "static": false
    },
    {
      "name": "get__ObjectPrefabKey",
      "params": [],
      "returns": "System.String",
      "static": false
    },
    {
      "name": "CreatedObject",
      "params": [
        {
          "name": "flow",
          "type": "app.UIFlowCommon.CreateObject"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "OnCreatedObject",
      "params": [
        {
          "name": "flow",
          "type": "app.UIFlowCommon.CreateObject"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "ShowedObject",
      "params": [
        {
          "name": "flow",
          "type": "app.UIFlowCommon.ShowObject"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "ChangeMainFlow",
      "params": [
        {
          "name": "flow",
          "type": "app.UIFlowBase"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "ChangeSubMenuEndFlow",
      "params": [
        {
          "name": "flow",
          "type": "app.UIFlowBase"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "ShowInputGuide",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "HideInputGuide",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "UpdateDispItem",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "MenuDecideEvent",
      "params": [
        {
          "name": "flow",
          "type": "app.UIFlowBase"
        },
        {
          "name": "decideMenuType",
          "type": "app.UICFNReplayInfo.MenuType"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": ".ctor",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<OnCreatedObject>g__setupParts|42_0",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    }
  ],
  "parent": "app.UIFlowCFNCommon.SelectMenuObjectParam",
  "size": 248,
  "type": "app.UICFNReplayInfo.FlowParamBase",
  "valuetype": false
}

8:52:55 PM · object.describe

{
  "fields": [
    {
      "name": "<MyReplayFilter>k__BackingField",
      "offset": 16,
      "static": false,
      "type": "app.network.api.Enum.MyReplayFilter"
    },
    {
      "name": "<UpdateTopInfoEvent>k__BackingField",
      "offset": 24,
      "static": false,
      "type": "System.Action`1<app.network.api.HatoClientAPI.Component.CommonReplayTopInfo>"
    },
    {
      "name": "<IsBattleResultDisp>k__BackingField",
      "offset": 32,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "<CurrentTab>k__BackingField",
      "offset": 36,
      "static": false,
      "type": "app.UICFNReplayTop.TabType"
    },
    {
      "name": "<CurrentRecommendPage>k__BackingField",
      "offset": 40,
      "static": false,
      "type": "System.Int32"
    },
    {
      "name": "<CurrentSearchTab>k__BackingField",
      "offset": 44,
      "static": false,
      "type": "app.UICFNReplayTopTabSearch.TabType"
    },
    {
      "name": "<CurrentSearchIdItem>k__BackingField",
      "offset": 48,
      "static": false,
      "type": "app.UICFNReplayTopTabSearchChildSearchId.SearchItem"
    },
    {
      "name": "<PostSearchDeatil>k__BackingField",
      "offset": 56,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Component.PostReplaySearchDetailedIn"
    },
    {
      "name": "<PostSearchFighterId>k__BackingField",
      "offset": 64,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Component.PostReplaySearchFighterIdIn"
    },
    {
      "name": "<PostSearchShortId>k__BackingField",
      "offset": 72,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Component.PostReplaySearchShortIdIn"
    },
    {
      "name": "<PostSearchReplayId>k__BackingField",
      "offset": 80,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdIn"
    }
  ],
  "methods": [
    {
      "name": "get_MyReplayFilter",
      "params": [],
      "returns": "app.network.api.Enum.MyReplayFilter",
      "static": false
    },
    {
      "name": "set_MyReplayFilter",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.Enum.MyReplayFilter"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_UpdateTopInfoEvent",
      "params": [],
      "returns": "System.Action`1<app.network.api.HatoClientAPI.Component.CommonReplayTopInfo>",
      "static": false
    },
    {
      "name": "set_UpdateTopInfoEvent",
      "params": [
        {
          "name": "value",
          "type": "System.Action`1<app.network.api.HatoClientAPI.Component.CommonReplayTopInfo>"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_IsBattleResultDisp",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "set_IsBattleResultDisp",
      "params": [
        {
          "name": "value",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_CurrentTab",
      "params": [],
      "returns": "app.UICFNReplayTop.TabType",
      "static": false
    },
    {
      "name": "set_CurrentTab",
      "params": [
        {
          "name": "value",
          "type": "app.UICFNReplayTop.TabType"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_CurrentRecommendPage",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "set_CurrentRecommendPage",
      "params": [
        {
          "name": "value",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_CurrentSearchTab",
      "params": [],
      "returns": "app.UICFNReplayTopTabSearch.TabType",
      "static": false
    },
    {
      "name": "set_CurrentSearchTab",
      "params": [
        {
          "name": "value",
          "type": "app.UICFNReplayTopTabSearch.TabType"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_CurrentSearchIdItem",
      "params": [],
      "returns": "app.UICFNReplayTopTabSearchChildSearchId.SearchItem",
      "static": false
    },
    {
      "name": "set_CurrentSearchIdItem",
      "params": [
        {
          "name": "value",
          "type": "app.UICFNReplayTopTabSearchChildSearchId.SearchItem"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_PostSearchDeatil",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Component.PostReplaySearchDetailedIn",
      "static": false
    },
    {
      "name": "set_PostSearchDeatil",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Component.PostReplaySearchDetailedIn"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_PostSearchFighterId",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Component.PostReplaySearchFighterIdIn",
      "static": false
    },
    {
      "name": "set_PostSearchFighterId",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Component.PostReplaySearchFighterIdIn"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_PostSearchShortId",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Component.PostReplaySearchShortIdIn",
      "static": false
    },
    {
      "name": "set_PostSearchShortId",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Component.PostReplaySearchShortIdIn"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_PostSearchReplayId",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdIn",
      "static": false
    },
    {
      "name": "set_PostSearchReplayId",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Component.PostReplaySearchReplayIdIn"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "ClearSearchInfo",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": ".ctor",
      "params": [],
      "returns": "System.Void",
      "static": false
    }
  ],
  "parent": "System.Object",
  "size": 88,
  "type": "app.UICFNReplayTop.TopTemporaryData",
  "valuetype": false
}

8:52:40 PM · type.find

{
  "h": 8,
  "static": true,
  "type": "app.UIFlowCFNCommon.SubUIObjectParam"
}

8:52:35 PM · type.find

{
  "h": 7,
  "static": true,
  "type": "app.UICFNReplayInfo.MenuType"
}

8:52:31 PM · type.find

{
  "h": 6,
  "static": true,
  "type": "app.UICFNReplayInfo.FlowParamBase"
}

8:52:25 PM · type.find

{
  "h": 5,
  "static": true,
  "type": "app.UICFNReplayTop.TopTemporaryData"
}```
```
8:53:50 PM · type.search UICFNReplayTop

309 of 215196 types
System.Collections.Generic.IReadOnlyCollection`1<app.UICFNReplayTopTabSearchChildSearchDetailes.StatePattern>
System.Collections.Generic.IList`1<app.UICFNReplayTopTabMyReplay.FlowParam.FilterMenuItem>
System.Collections.Generic.IReadOnlyList`1<app.UICFNReplayTopTabSearch.TabType>
app.UICFNReplayTopTabSearchChildSearchDetailes.FlowParam.<>c
System.Collections.Generic.IList`1<app.UICFNReplayTopTabSearchChildSearchDetailes.MenuType>
app.UICFNReplayTopTabRecommend.NoDataMainFlow
System.Array.InternalEnumerator`1<app.UICFNReplayTopTabReplayList.SortMenuItem>
app.UIFlowCFNCommon.CallReplayRegisterTopApiFlow`1.<>c<app.UICFNReplayTopTabListBase.FlowParamBase>
System.Collections.Generic.IEnumerable`1<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>
app.UIFlowCFNCommon.CallReplayRegisterTopApiFlow`1<app.UICFNReplayTopTabListBase.FlowParamBase>
System.Array.InternalEnumerator`1<app.UICFNReplayTopTabSearchChildSearchDetailes.LeftMenuType>
app.UIFlowAPIBase`1<app.UICFNReplayTopTabListBase.FlowParamBase>
app.UIFlowCFNCommon.WaitSubMenuFlow`1<app.UICFNReplayTopTabSearchChildSearchDetailes.FlowParam>
app.UICFNReplayTopTabListBase.MainFlow
System.Array.InternalEnumerator`1<app.UICFNReplayTopTabLocal.StatePattern>
app.UIFlowCFNCommon.UIFlowDialogCheck`1<app.UICFNReplayTopTabReplayList.FlowParam>
System.Collections.Generic.IList`1<app.UICFNReplayTopTabListBase.StatePattern>
app.UICFNReplayTopTabMyReplay.NoDataMainFlow
System.Collections.Generic.IEnumerator`1<app.UICFNReplayTopTabListBase.RecommendPageNum>
System.Collections.Generic.IReadOnlyCollection`1<app.UICFNReplayTopTabSearchChildSearchDetailes.PlMenuType>
System.Collections.Generic.ICollection`1<app.UICFNReplayTopTabSearchChildSearchDetailes.RightMenuType>
app.UICFNReplayTopTabReplayList.MultiOptionFlow
app.UICFNReplayTopTabSearchChildSearchId.CallSearchShortIdApiFlow
System.Collections.Generic.IEnumerable`1<app.UICFNReplayTopTabSearchChildSearchDetailes.RightMenuType>
app.UIFlowCFNCommon.WaitSubMenuFlow`1<app.UICFNReplayTopTabSearchChildSearchId.FlowParam>
app.UICFNReplayTopTabSearchChildSearchDetailes.FlowParam.<>c__DisplayClass79_0
app.UICFNReplayTopTabReplayList.FlowParam
app.UICFNReplayTopTabSearchChildSearchId.CallSearchShortIdRestoreApiFlow
app.UIFlowCFNCommon.CallReplayRegisterCancelTopApiFlow`1.<>c__DisplayClass0_0<app.UICFNReplayTopTabReplayList.FlowParam>
System.Collections.Generic.IArraySortHelper`1<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>
app.UIFlowCFNCommon.CallReplayDownloadUrlApiFlow`1.<>c__DisplayClass0_0<app.UICFNReplayTopTabListBase.FlowParamBase>
app.UICFNReplayTop.FlowParam
app.UICFNReplayTopTabSearchChildSearchId.ShowSearchResultNoneFlow
app.UICFNReplayTopTabReplayList.SortMenuItem[]
System.Predicate`1<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>
app.UIFlowCFNCommon.CallReplayRegisterTopApiFlow`1.<>c__DisplayClass0_1<app.UICFNReplayTopTabListBase.FlowParamBase>
app.UICFNReplayTop
System.Collections.Generic.ICollection`1<app.UICFNReplayTopTabReplayList.SortMenuItem>
System.Collections.Generic.IReadOnlyCollection`1<app.UICFNReplayTopTabMyReplay.FlowParam.FilterMenuItem>
System.Array.InternalEnumerator`1<app.UICFNReplayTopTabListBase.StatePattern>
app.UICFNReplayTopTabSearchChildSearchDetailes.SwitchType[]
app.UICFNReplayTopTabSearchChildSearchDetailes.FlowParam.<>c__DisplayClass77_0
app.UICFNReplayTopTabSearchChildSearchDetailes.MainFlow.InputDelegates
System.Collections.Generic.IEnumerable`1<app.UICFNReplayTopTabReplayList.SortMenuItem>
app.UICFNReplayTopTabListBase.SortType[]
System.Collections.Generic.DefaultComparer`1<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>
app.UICFNReplayTopTabSearchChildSearchId.SearchItem
System.Collections.Generic.IList`1<app.UICFNReplayTopTabMyReplay.ChildTabIndex>
app.UICFNReplayTopTabReplayList.FlowParam.<>c
System.Collections.Generic.IEnumerator`1<app.UICFNReplayTop.TabType>
app.UICFNReplayTopTabSearchChildSearchId.CallSearchReplayIdRestoreApiFlow
System.Collections.Generic.IEnumerable`1<app.UICFNReplayTopTabSearchChildSearchDetailes.MenuType>
System.Collections.Generic.IReadOnlyList`1<app.UICFNReplayTopTabSearchChildSearchDetailes.RightMenuType>
app.UICFNReplayTopTabListBase.NoDataMainFlow
app.UICFNReplayTopTabSearchChildSearchDetailes.CallSearchDetailedApiFlow
System.Action`1<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>
app.UICFNReplayTopTabReplayList.MainFlow
System.Collections.Generic.IReadOnlyCollection`1<app.UICFNReplayTopTabSearchChildSearchDetailes.SwitchType>
app.UICFNReplayTopTabListBase.NoDataMainFlow.<>c
System.Collections.Generic.ICollection`1<app.UICFNReplayTopTabSearchChildSearchDetailes.LeftMenuType>
System.Collections.Generic.ICollection`1<app.UICFNReplayTop.TabType>
System.Collections.Generic.IList`1<app.UICFNReplayTopTabListBase.SortType>
app.UICFNReplayTopTabSearchChildSearchId.CallSearchReplayIdRestoreApiFlow.<>c__DisplayClass0_0
app.UICFNReplayTopTabLocal.MainFlow.MainInputDelegates
System.Collections.Generic.IReadOnlyCollection`1<app.UICFNReplayTopTabSearchChildSearchDetailes.LeftMenuType>
System.Collections.Generic.Comparer`1<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>
System.Collections.Generic.ComparisonComparer`1<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>
System.Collections.Generic.IReadOnlyCollection`1<app.UICFNReplayTopTabListBase.StatePattern>
System.Collections.Generic.IList`1<app.UICFNReplayTopTabSearchChildSearchDetailes.StatePattern>
app.UIFlowCFNCommon.ShowSubReplaySearchResultFlow`1<app.UICFNReplayTopTabSearchChildSearchId.FlowParam>
app.UICFNReplayTopTabReplayList.PreReplayRegisterCancelTopApiFlow
System.Collections.Generic.IList`1<app.UICFNReplayTopTabSearchChildSearchDetailes.RightMenuType>
System.Collections.Generic.IList`1<app.UICFNReplayTopTabSearchChildSearchDetailes.SwitchType>
app.UICFNReplayTopTabListBase.RecommendPageNum
System.Collections.Generic.IReadOnlyList`1<app.UICFNReplayTopTabLocal.StatePattern>
System.Collections.Generic.IEnumerator`1<app.UICFNReplayTopTabListBase.SortType>
app.UICFNReplayTopTabSearchChildSearchDetailes
System.Collections.Generic.IReadOnlyList`1<app.UICFNReplayTopTabListBase.RecommendPageNum>
app.UICFNReplayTopTabListBase.FilterMenuWaitFlow.<>c
app.UICFNReplayTopTabListBase.FilterMenuWaitFlow.MainInputDelegates
System.Collections.Generic.IReadOnlyCollection`1<app.UICFNReplayTopTabSearchChildSearchDetailes.RightMenuType>
app.UICFNReplayTopTabSearchChildSearchDetailes.PlMenuType
System.Collections.Generic.IReadOnlyCollection`1<app.UICFNReplayTopTabReplayList.SortMenuItem>
System.Array.InternalEnumerator`1<app.UICFNReplayTopTabSearchChildSearchDetailes.StatePattern>
app.UICFNReplayTopTabMyReplay
app.UIFlowCFNCommon.CallReplayDownloadUrlApiFlow`1.<>c<app.UICFNReplayTopTabListBase.FlowParamBase>
System.Collections.Generic.IReadOnlyCollection`1<app.UICFNReplayTop.TabType>
System.Array.InternalEnumerator`1<app.UICFNReplayTopTabListBase.SortType>
app.UICFNReplayTopTabSearchChildSearchDetailes.EditSingleMenuFlow.InputDelegates
app.UICFNReplayTopTabSearchChildSearchDetailes.ShowSearchResultNoneFlow
System.Collections.Generic.IReadOnlyList`1<app.UICFNReplayTopTabSearchChildSearchDetailes.StatePattern>
app.UICFNReplayTopTabRecommend
app.UICFNReplayTopTabSearchChildSearchDetailes.ResetCheckFlow
app.UICFNReplayTopTabSearch.TabType
System.Collections.Generic.ICollection`1<app.UICFNReplayTopTabListBase.RecommendPageNum>
app.UICFNReplayTopTabSearchChildSearchId.LoadWaitFlow
System.Collections.Generic.IReadOnlyCollection`1<app.UICFNReplayTopTabListBase.SortType>
app.UICFNReplayTopTabSearchChildSearchDetailes.RightMenuType
app.UICFNReplayTopTabSearchChildSearchDetailes.EditSingleMenuFlow
System.Collections.Generic.IEnumerable`1<app.UICFNReplayTopTabListBase.SortType>
app.UICFNReplayTopTabRecommend.FlowParam.<>c__DisplayClass8_1
System.Collections.Generic.List`1<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>
app.UICFNReplayTopTabSearchChildSearchId.CallSearchFighterIdRestoreApiFlow
app.UIFlowAPIBase`1<app.UICFNReplayTopTabSearchChildSearchId.FlowParam>
app.UICFNReplayTopTabSearchChildSearchId.InputSearchIdWindowFlow
System.Collections.Generic.ICollection`1<app.UICFNReplayTopTabMyReplay.FlowParam.FilterMenuItem>
app.UICFNReplayTopTabSearchChildSearchId
System.Comparison`1<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>
app.UICFNReplayTopTabListBase.SortType
app.UICFNReplayTopTabLocal.MultiMenuFlow
System.Collections.Generic.IComparer`1<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>
System.Collections.Generic.ICollection`1<app.UICFNReplayTopTabMyReplay.ChildTabIndex>
app.UICFNReplayTopTabLocal.FlowParam
System.Collections.Generic.List`1.Enumerator<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>
app.UIFlowCFNCommon.ShowReplayDownloadUrlNoneFlow`1<app.UICFNReplayTopTabListBase.FlowParamBase>
app.UICFNReplayTopTabSearchChildSearchDetailes.StatePattern[]
app.UICFNReplayTopTabSearchChildSearchId.CallSearchReplayIdApiFlow.<>c__DisplayClass0_0
System.Collections.Generic.IEnumerable`1<app.UICFNReplayTopTabSearchChildSearchDetailes.StatePattern>
app.UIFlowCFNCommon.UIFlowDialogConfirm`1<app.UICFNReplayTopTabSearchChildSearchDetailes.FlowParam>
app.UICFNReplayTopTabSearchChildSearchId.CallSearchFighterIdRestoreApiFlow.<>c__DisplayClass0_0
app.UIFlowCFNCommon.UIFlowDialogCheck`1<app.UICFNReplayTopTabSearchChildSearchDetailes.FlowParam>
app.UICFNReplayTopTabListBase.ControlType
System.Array.InternalEnumerator`1<app.UICFNReplayTopTabSearchChildSearchDetailes.RightMenuType>
app.UICFNReplayTopTabReplayList.SortMenuItem
app.UICFNReplayTop.FlowParam.LoadWaitForRestoreFlow
System.Collections.Generic.ICollection`1<app.UICFNReplayTopTabSearch.TabType>
app.UICFNReplayTopTabMyReplay.FlowParam
System.Collections.Generic.IEnumerable`1<app.UICFNReplayTopTabSearch.TabType>
app.UICFNReplayTopTabMyReplay.MainFlow
app.UIFlowAPI`1<app.UICFNReplayTopTabSearchChildSearchDetailes.FlowParam>
app.UICFNReplayTopTabSearch
app.UICFNReplayTopTabSearchChildSearchId.MainFlow
app.UICFNReplayTopTabListBase.MainFlow.InputDelegates
System.Collections.Generic.ICollection`1<app.UICFNReplayTopTabSearchChildSearchDetailes.StatePattern>
app.UICFNReplayTopTabSearchChildSearchId.CallSearchFighterIdApiFlow
System.Collections.Generic.IReadOnlyList`1<app.UICFNReplayTopTabListBase.SortType>
System.Collections.Generic.ICollection`1<app.UICFNReplayTopTabSearchChildSearchDetailes.PlMenuType>
app.UICFNReplayTopTabSearch.FlowParam
System.Collections.Generic.IEnumerator`1<app.UICFNReplayTopTabListBase.ControlType>
System.Collections.Generic.ICollection`1<app.UICFNReplayTopTabSearchChildSearchDetailes.SwitchType>
System.Collections.Generic.IReadOnlyCollection`1<app.UICFNReplayTopTabSearch.TabType>
app.UICFNReplayTopTabSearchChildSearchDetailes.SwitchType
app.UICFNReplayTopTabSearchChildSearchDetailes.StatePattern
System.Collections.Generic.IReadOnlyList`1<app.UICFNReplayTopTabSearchChildSearchDetailes.PlMenuType>
app.UICFNReplayTopTabListBase.SortMenuWaitFlow.MainInputDelegates
app.UICFNReplayTopTabSearchChildSearchDetailes.CallSearchDetailedApiFlow.<>c__DisplayClass0_0
System.Collections.Generic.IEnumerator`1<app.UICFNReplayTopTabReplayList.SortMenuItem>
System.Array.InternalEnumerator`1<app.UICFNReplayTop.TabType>
System.Collections.Generic.IEnumerator`1<app.UICFNReplayTopTabSearchChildSearchDetailes.PlMenuType>
app.UICFNReplayTopTabReplayList.PreRegisterCancelOtherVersionApiFlow
System.Collections.Generic.IEnumerator`1<app.UICFNReplayTopTabSearchChildSearchDetailes.StatePattern>
System.Array.InternalEnumerator`1<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>
app.UICFNReplayTopTabSearchChildSearchId.SearchItem[]
System.Collections.Generic.IList`1<app.UICFNReplayTopTabSearchChildSearchDetailes.PlMenuType>
System.Collections.Generic.IReadOnlyCollection`1<app.UICFNReplayTopTabListBase.RecommendPageNum>
app.UICFNReplayTopTabSearch.TabType[]
app.UICFNReplayTopTabSearchChildSearchId.CallSearchShortIdRestoreApiFlow.<>c__DisplayClass0_0
System.Array.InternalEnumerator`1<app.UICFNReplayTopTabListBase.ControlType>
app.UICFNReplayTopTabListBase.StatePattern[]
app.UIFlowAPI`1<app.UICFNReplayTopTabMyReplay.FlowParam>
app.UIFlowCFNCommon.CallReplayDownloadUrlApiFlow`1<app.UICFNReplayTopTabListBase.FlowParamBase>
app.UICFNReplayTopTabReplayList.CallRegisterCancelOtherVersionApiFlow
app.UICFNReplayTop.TabType[]
app.UIFlowAPIBase`1<app.UICFNReplayTopTabMyReplay.FlowParam>
System.Collections.ObjectModel.ReadOnlyCollection`1<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>
app.UIFlowAPI`1<app.UICFNReplayTopTabReplayList.FlowParam>
app.UICFNReplayTopTabListBase.MultiFlow.InputDelegates
app.UICFNReplayTopTabMyReplay.FlowParam.FilterMenuItem[]
app.UICFNReplayTopTabListBase.ReplayMenuWaitFlow
System.Collections.Generic.IList`1<app.UICFNReplayTopTabLocal.StatePattern>
System.Collections.Generic.IReadOnlyCollection`1<app.UICFNReplayTopTabMyReplay.ChildTabIndex>
System.Array.InternalEnumerator`1<app.UICFNReplayTopTabSearchChildSearchDetailes.SwitchType>
app.UIFlow`1<app.UICFNReplayTopTabReplayList.FlowParam>
app.UIFlow`1<app.UICFNReplayTop.FlowParam>
app.UICFNReplayTopTabMyReplay.FlowParam.FilterMenuItem
app.UICFNReplayTopTabMyReplay.NoDataMainFlow.MainInputDelegates
System.Collections.Generic.IReadOnlyCollection`1<app.UICFNReplayTopTabLocal.StatePattern>
System.Collections.Generic.IReadOnlyList`1<app.UICFNReplayTopTabSearchChildSearchDetailes.SwitchType>
app.UICFNReplayTopTabReplayList.FlowParam.<>c__DisplayClass10_0
System.Collections.Generic.ICollection`1<app.UICFNReplayTopTabSearchChildSearchDetailes.MenuType>
System.Collections.Generic.IReadOnlyList`1<app.UICFNReplayTopTabMyReplay.ChildTabIndex>
app.UICFNReplayTopTabMyReplay.ChildTabIndex[]
app.UICFNReplayTopTabRecommend.FlowParam
app.UICFNReplayTopTabListBase.SortMenuWaitFlow.<>c
app.UIFlowCFNCommon.CallReplayRegisterCancelTopApiFlow`1.<>c<app.UICFNReplayTopTabReplayList.FlowParam>
System.Array.InternalEnumerator`1<app.UICFNReplayTopTabSearchChildSearchDetailes.PlMenuType>
app.UIFlow`1<app.UICFNReplayTopTabLocal.FlowParam>
app.UICFNReplayTopTabSearchChildSearchDetailes.CallSearchDetailedRestoreApiFlow
app.UICFNReplayTopTabListBase.MultiFlow
app.UICFNReplayTopTabLocal.NoDataMainFlow
System.Collections.Generic.IReadOnlyCollection`1<app.UICFNReplayTopTabSearchChildSearchDetailes.MenuType>
System.Collections.Generic.IReadOnlyList`1<app.UICFNReplayTopTabSearchChildSearchDetailes.MenuType>
System.Collections.Generic.IEnumerable`1<app.UICFNReplayTopTabMyReplay.ChildTabIndex>
app.UIFlowCFNCommon.CallReplayRegisterTopApiFlow`1.<>c__DisplayClass0_0<app.UICFNReplayTopTabListBase.FlowParamBase>
System.Collections.Generic.IReadOnlyList`1<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>
System.Converter`2<app.UICFNReplayTopTabSearchChildSearchId.SearchItem,!!0>
System.Array.InternalEnumerator`1<app.UICFNReplayTopTabSearch.TabType>
app.UIFlowAPI`1<app.UICFNReplayTopTabListBase.FlowParamBase>
System.Collections.Generic.ArraySortHelper`1<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>
app.UICFNReplayTopTabSearchChildSearchDetailes.LeftMenuType
System.Array.InternalEnumerator`1<app.UICFNReplayTopTabSearchChildSearchDetailes.MenuType>
app.UIFlow`1<app.UICFNReplayTopTabSearchChildSearchId.FlowParam>
app.UICFNReplayTopTabSearchChildSearchId.FlowParam
app.UICFNReplayTopTabSearchChildSearchId.MainFlow.InputDelegates
System.Collections.Generic.IEnumerable`1<app.UICFNReplayTopTabMyReplay.FlowParam.FilterMenuItem>
app.UICFNReplayTopTabSearchChildSearchDetailes.FlowParam
app.UICFNReplayTopTabListBase.FilterMenuWaitFlow
app.UIFlowCFNCommon.UIFlowDialogConfirm`1<app.UICFNReplayTopTabSearchChildSearchId.FlowParam>
app.UICFNReplayTopTabListBase.FlowParamBase.<>c__DisplayClass80_0
System.Collections.Generic.IEnumerator`1<app.UICFNReplayTopTabSearchChildSearchDetailes.MenuType>
System.Collections.Generic.IList`1<app.UICFNReplayTopTabSearch.TabType>
app.UICFNReplayTopTabMyReplay.ChildTabIndex
app.UICFNReplayTopTabListBase.RecommendPageNum[]
System.Array.InternalEnumerator`1<app.UICFNReplayTopTabListBase.RecommendPageNum>
app.UIFlowCFNCommon.ShowSubReplaySearchResultDetailedFlow`1<app.UICFNReplayTopTabSearchChildSearchDetailes.FlowParam>
System.Collections.Generic.IReadOnlyList`1<app.UICFNReplayTopTabMyReplay.FlowParam.FilterMenuItem>
app.UIFlowCFNCommon.UIFlowDialogConfirm`1<app.UICFNReplayTopTabListBase.FlowParamBase>
app.UIFlowAPIBase`1<app.UICFNReplayTopTabSearchChildSearchDetailes.FlowParam>
app.UIFlowCFNCommon.CallReplayRegisterCancelTopApiFlow`1<app.UICFNReplayTopTabReplayList.FlowParam>
System.Collections.Generic.IList`1<app.UICFNReplayTopTabListBase.RecommendPageNum>
app.UICFNReplayTopTabLocal
app.UICFNReplayTopTabSearchChildSearchDetailes.LoadWaitFlow
System.Collections.Generic.IReadOnlyCollection`1<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>
app.UICFNReplayTopTabListBase
app.UICFNReplayTopTabRecommend.FlowParam.<>c__DisplayClass8_0
System.Collections.Generic.IList`1<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>
System.Collections.Generic.IEnumerator`1<app.UICFNReplayTopTabSearchChildSearchDetailes.LeftMenuType>
app.UICFNReplayTopTabLocal.ReplayMenuWaitFlow
System.Collections.Generic.IEnumerable`1<app.UICFNReplayTopTabSearchChildSearchDetailes.SwitchType>
app.UICFNReplayTopTabLocal.PlayReplayFlow
System.Collections.Generic.IEnumerable`1<app.UICFNReplayTopTabListBase.RecommendPageNum>
System.Collections.Generic.ICollection`1<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>
app.UIFlowCFNCommon.CallReplayDownloadUrlApiFlow`1.<>c__DisplayClass0_2<app.UICFNReplayTopTabListBase.FlowParamBase>
System.Collections.Generic.IEnumerator`1<app.UICFNReplayTopTabSearchChildSearchDetailes.RightMenuType>
System.Collections.Generic.IList`1<app.UICFNReplayTopTabReplayList.SortMenuItem>
app.UICFNReplayTopTabReplayList.FlowParam.<>c__DisplayClass7_0
System.Collections.Generic.IList`1<app.UICFNReplayTopTabListBase.ControlType>
app.UICFNReplayTopTabSearchChildSearchDetailes.MainFlow
System.Collections.Generic.IEnumerator`1<app.UICFNReplayTopTabMyReplay.FlowParam.FilterMenuItem>
app.UICFNReplayTopTabLocal.FlowParam.<>c
app.UICFNReplayTopTabSearchChildSearchDetailes.PlMenuType[]
System.Collections.Generic.ICollection`1<app.UICFNReplayTopTabListBase.StatePattern>
app.UICFNReplayTopTabListBase.FlowParamBase
System.Collections.Generic.ICollection`1<app.UICFNReplayTopTabListBase.SortType>
app.UICFNReplayTopTabLocal.MultiFlow
System.Collections.Generic.IList`1<app.UICFNReplayTop.TabType>
System.Collections.Generic.IEnumerator`1<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>
app.UICFNReplayTopTabRecommend.MainFlow.InputDelegates
app.UICFNReplayTopTabListBase.ControlType[]
System.Collections.Generic.IEnumerable`1<app.UICFNReplayTopTabListBase.ControlType>
app.UIFlow`1<app.UICFNReplayTopTabSearchChildSearchDetailes.FlowParam>
app.UICFNReplayTopTabReplayList
System.Collections.Generic.IEnumerator`1<app.UICFNReplayTopTabLocal.StatePattern>
System.Array.InternalEnumerator`1<app.UICFNReplayTopTabMyReplay.FlowParam.FilterMenuItem>
app.UICFNReplayTopTabSearchChildSearchDetailes.MenuType[]
app.UICFNReplayTopTabMyReplay.MainFlow.InputDelegates
System.Collections.Generic.ICollection`1<app.UICFNReplayTopTabListBase.ControlType>
app.UICFNReplayTopTabSearchChildSearchDetailes.CallSearchDetailedRestoreApiFlow.<>c__DisplayClass0_0
app.UICFNReplayTop.TopTemporaryData
app.UICFNReplayTopTabSearchChildSearchDetailes.MenuType
app.UICFNReplayTopTabSearchChildSearchId.CallSearchShortIdApiFlow.<>c__DisplayClass0_0
System.Collections.Generic.IEnumerable`1<app.UICFNReplayTopTabLocal.StatePattern>
app.UICFNReplayTopTabSearchChildSearchId.CallSearchReplayIdApiFlow
System.Collections.Generic.IReadOnlyList`1<app.UICFNReplayTopTabListBase.ControlType>
app.UIFlowCFNCommon.CallReplayDownloadUrlApiFlow`1.<>c__DisplayClass0_1<app.UICFNReplayTopTabListBase.FlowParamBase>
app.UICFNReplayTopTabListBase.SortMenuWaitFlow
System.Collections.Generic.IReadOnlyList`1<app.UICFNReplayTopTabSearchChildSearchDetailes.LeftMenuType>
app.UICFNReplayTopTabLocal.NoDataMainFlow.<>c
System.Collections.Generic.IEnumerable`1<app.UICFNReplayTopTabListBase.StatePattern>
System.Collections.Generic.IEnumerator`1<app.UICFNReplayTopTabMyReplay.ChildTabIndex>
app.UICFNReplayTopTabSearchChildSearchDetailes.RightMenuType[]
app.UICFNReplayTopTabListBase.FlowParamBase.<>c__DisplayClass69_0
System.Collections.Generic.IEnumerable`1<app.UICFNReplayTop.TabType>
System.Collections.Generic.IReadOnlyList`1<app.UICFNReplayTopTabReplayList.SortMenuItem>
app.UICFNReplayTopTabSearchChildSearchDetailes.FlowParam.<>c__DisplayClass83_0
System.Collections.Generic.IReadOnlyList`1<app.UICFNReplayTop.TabType>
app.UIFlowAPIBase`1<app.UICFNReplayTopTabReplayList.FlowParam>
app.UIFlow`1<app.UICFNReplayTopTabMyReplay.FlowParam>
app.UICFNReplayTopTabListBase.MultiMenuFlow
System.Collections.Generic.IEnumerator`1<app.UICFNReplayTopTabListBase.StatePattern>
System.Collections.Generic.IEnumerator`1<app.UICFNReplayTopTabSearchChildSearchDetailes.SwitchType>
app.UICFNReplayTopTabSearchChildSearchDetailes.EditHomeFlow
System.Collections.Generic.ICollection`1<app.UICFNReplayTopTabLocal.StatePattern>
app.UICFNReplayTopTabLocal.StatePattern[]
System.Collections.Generic.IEnumerator`1<app.UICFNReplayTopTabSearch.TabType>
app.UICFNReplayTopTabSearchChildSearchDetailes.LeftMenuType[]
System.Array.InternalEnumerator`1<app.UICFNReplayTopTabMyReplay.ChildTabIndex>
app.UICFNReplayTopTabSearchChildSearchDetailes.FlowParam.<>c__DisplayClass81_0
app.UIFlow`1<app.UICFNReplayTopTabListBase.FlowParamBase>
app.UICFNReplayTopTabSearchChildSearchDetailes.EditFlow
app.UICFNReplayTopTabRecommend.NoDataMainFlow.MainInputDelegates
app.UICFNReplayTop.TabType
System.Collections.Generic.IEnumerable`1<app.UICFNReplayTopTabSearchChildSearchDetailes.LeftMenuType>
app.UICFNReplayTopTabLocal.LoadWaitFlow
System.Collections.Generic.IReadOnlyCollection`1<app.UICFNReplayTopTabListBase.ControlType>
app.UICFNReplayTopTabListBase.MenuCloseFlow
app.UICFNReplayTopTabLocal.StatePattern
app.UICFNReplayTopTabSearchChildSearchId.CallSearchFighterIdApiFlow.<>c__DisplayClass0_0
app.UIFlowAPI`1<app.UICFNReplayTopTabSearchChildSearchId.FlowParam>
app.UICFNReplayTopTabListBase.StatePattern
System.Collections.Generic.IReadOnlyList`1<app.UICFNReplayTopTabListBase.StatePattern>
System.Collections.Generic.IEnumerable`1<app.UICFNReplayTopTabSearchChildSearchDetailes.PlMenuType>
app.UICFNReplayTopTabLocal.MultiFlow.InputDelegates
app.UICFNReplayTopTabListBase.NoDataMainFlow.MainInputDelegates
app.UIFlowCFNCommon.CallReplayRegisterCancelTopApiFlow`1.<>c__DisplayClass0_1<app.UICFNReplayTopTabReplayList.FlowParam>
app.UICFNReplayTopTabMyReplay.CallMyReplayApiFlow
app.UICFNReplayTopTabRecommend.MainFlow
System.Collections.Generic.IList`1<app.UICFNReplayTopTabSearchChildSearchDetailes.LeftMenuType>
app.UICFNReplayTopTabLocal.MainFlow```

## Batch 3: the search-by-ID child, its param, SearchItem enum, API flow, input dialog flow, download flow
```
8:57:51 PM · object.describe

{
  "fields": [],
  "methods": [
    {
      "name": "OnCallApi",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "OnApiCancel",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "OnExitEvent",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": ".ctor",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<OnCallApi>g__ErrorLog|0_3",
      "params": [
        {
          "name": "info",
          "type": "app.network.api.HatoClientAPI.Component.CommonReplayDownloadInfo"
        },
        {
          "name": "error",
          "type": "app.error.ErrorCode"
        }
      ],
      "returns": "System.Void",
      "static": true
    }
  ],
  "parent": "app.UIFlowAPI`1<app.UICFNReplayTopTabListBase.FlowParamBase>",
  "size": 40,
  "type": "app.UIFlowCFNCommon.CallReplayDownloadUrlApiFlow`1<app.UICFNReplayTopTabListBase.FlowParamBase>",
  "valuetype": false
}

8:57:49 PM · object.describe

{
  "fields": [],
  "methods": [
    {
      "name": "OnEnter",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "OnExit",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "OnResultCallback",
      "params": [
        {
          "name": "searchId",
          "type": "System.String"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": ".ctor",
      "params": [],
      "returns": "System.Void",
      "static": false
    }
  ],
  "parent": "app.UIFlow`1<app.UICFNReplayTopTabSearchChildSearchId.FlowParam>",
  "size": 40,
  "type": "app.UICFNReplayTopTabSearchChildSearchId.InputSearchIdWindowFlow",
  "valuetype": false
}

8:57:46 PM · object.describe

{
  "fields": [],
  "methods": [
    {
      "name": "OnCallApi",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "OnApiCancel",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": ".ctor",
      "params": [],
      "returns": "System.Void",
      "static": false
    }
  ],
  "parent": "app.UIFlowAPI`1<app.UICFNReplayTopTabSearchChildSearchId.FlowParam>",
  "size": 40,
  "type": "app.UICFNReplayTopTabSearchChildSearchId.CallSearchReplayIdApiFlow",
  "valuetype": false
}

8:57:44 PM · object.describe

{
  "fields": [
    {
      "name": "value__",
      "offset": 16,
      "static": false,
      "type": "System.Int32"
    },
    {
      "name": "FIGHTER_ID",
      "offset": 16,
      "static": true,
      "type": "app.UICFNReplayTopTabSearchChildSearchId.SearchItem"
    },
    {
      "name": "SHORT_ID",
      "offset": 16,
      "static": true,
      "type": "app.UICFNReplayTopTabSearchChildSearchId.SearchItem"
    },
    {
      "name": "REPLAY_ID",
      "offset": 16,
      "static": true,
      "type": "app.UICFNReplayTopTabSearchChildSearchId.SearchItem"
    },
    {
      "name": "NUM",
      "offset": 16,
      "static": true,
      "type": "app.UICFNReplayTopTabSearchChildSearchId.SearchItem"
    }
  ],
  "methods": [],
  "parent": "System.Enum",
  "size": 20,
  "type": "app.UICFNReplayTopTabSearchChildSearchId.SearchItem",
  "valuetype": true
}

8:57:38 PM · object.describe

{
  "fields": [
    {
      "name": "<SearchFighterId>k__BackingField",
      "offset": 120,
      "static": false,
      "type": "System.String"
    },
    {
      "name": "<SearchShortId>k__BackingField",
      "offset": 128,
      "static": false,
      "type": "System.UInt32"
    },
    {
      "name": "<SearchReplayId>k__BackingField",
      "offset": 136,
      "static": false,
      "type": "System.String"
    },
    {
      "name": "<SearchItemList>k__BackingField",
      "offset": 144,
      "static": false,
      "type": "System.Collections.Generic.List`1<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>"
    },
    {
      "name": "IsNoDataRestore",
      "offset": 152,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "<TextInputDialogWidget>k__BackingField",
      "offset": 160,
      "static": false,
      "type": "app.UITextInputDialog"
    },
    {
      "name": "<SearchResultList>k__BackingField",
      "offset": 168,
      "static": false,
      "type": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonReplayInfo>"
    },
    {
      "name": "<TopTemporaryData>k__BackingField",
      "offset": 176,
      "static": false,
      "type": "app.UICFNReplayTop.TopTemporaryData"
    },
    {
      "name": "<IsRestore>k__BackingField",
      "offset": 184,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "_ScrollList",
      "offset": 192,
      "static": false,
      "type": "app.UIPartsScrollList"
    }
  ],
  "methods": [
    {
      "name": "get_SearchFighterId",
      "params": [],
      "returns": "System.String",
      "static": false
    },
    {
      "name": "set_SearchFighterId",
      "params": [
        {
          "name": "value",
          "type": "System.String"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_SearchShortId",
      "params": [],
      "returns": "System.UInt32",
      "static": false
    },
    {
      "name": "set_SearchShortId",
      "params": [
        {
          "name": "value",
          "type": "System.UInt32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_SearchReplayId",
      "params": [],
      "returns": "System.String",
      "static": false
    },
    {
      "name": "set_SearchReplayId",
      "params": [
        {
          "name": "value",
          "type": "System.String"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_FocusIndex",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "get_SearchItemList",
      "params": [],
      "returns": "System.Collections.Generic.List`1<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>",
      "static": false
    },
    {
      "name": "set_SearchItemList",
      "params": [
        {
          "name": "value",
          "type": "System.Collections.Generic.List`1<app.UICFNReplayTopTabSearchChildSearchId.SearchItem>"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_TextInputDialogWidget",
      "params": [],
      "returns": "app.UITextInputDialog",
      "static": false
    },
    {
      "name": "set_TextInputDialogWidget",
      "params": [
        {
          "name": "value",
          "type": "app.UITextInputDialog"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_SearchResultList",
      "params": [],
      "returns": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonReplayInfo>",
      "static": false
    },
    {
      "name": "set_SearchResultList",
      "params": [
        {
          "name": "value",
          "type": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonReplayInfo>"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_TopTemporaryData",
      "params": [],
      "returns": "app.UICFNReplayTop.TopTemporaryData",
      "static": false
    },
    {
      "name": "set_TopTemporaryData",
      "params": [
        {
          "name": "value",
          "type": "app.UICFNReplayTop.TopTemporaryData"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_IsRestore",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "set_IsRestore",
      "params": [
        {
          "name": "value",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": ".ctor",
      "params": [
        {
          "name": "topTemporaryData",
          "type": "app.UICFNReplayTop.TopTemporaryData"
        },
        {
          "name": "isRestore",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_ObjectPrefabKey",
      "params": [],
      "returns": "System.String",
      "static": false
    },
    {
      "name": "CreatedObject",
      "params": [
        {
          "name": "flow",
          "type": "app.UIFlowCommon.CreateObject"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "ShowedObject",
      "params": [
        {
          "name": "flow",
          "type": "app.UIFlowCommon.ShowObject"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "OnEnd",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "ChangeMainFlow",
      "params": [
        {
          "name": "flow",
          "type": "app.UIFlowBase"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "ChangeSubMenuEndFlow",
      "params": [
        {
          "name": "flow",
          "type": "app.UIFlowBase"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "UpdateScrollList",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<CreatedObject>g__setupParts|39_0",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    }
  ],
  "parent": "app.UIFlowCFNCommon.TabItemObjectParam",
  "size": 200,
  "type": "app.UICFNReplayTopTabSearchChildSearchId.FlowParam",
  "valuetype": false
}

8:57:35 PM · object.describe

{
  "fields": [],
  "methods": [
    {
      "name": "Start",
      "params": [
        {
          "name": "param",
          "type": "app.UICFNReplayTopTabSearchChildSearchId.FlowParam"
        }
      ],
      "returns": "app.UIFlowCFNCommon.ChildTabFlowData",
      "static": true
    },
    {
      "name": "IsMain",
      "params": [
        {
          "name": "handle",
          "type": "app.IUIFlowHandle"
        }
      ],
      "returns": "System.Boolean",
      "static": true
    },
    {
      "name": ".ctor",
      "params": [],
      "returns": "System.Void",
      "static": false
    }
  ],
  "parent": "System.Object",
  "size": 16,
  "type": "app.UICFNReplayTopTabSearchChildSearchId",
  "valuetype": false
}

8:57:18 PM · type.find

{
  "h": 14,
  "static": true,
  "type": "app.UIFlowCFNCommon.CallReplayDownloadUrlApiFlow`1<app.UICFNReplayTopTabListBase.FlowParamBase>"
}

8:57:11 PM · type.find

{
  "h": 13,
  "static": true,
  "type": "app.UICFNReplayTopTabSearchChildSearchId.InputSearchIdWindowFlow"
}

8:57:05 PM · type.find

{
  "h": 12,
  "static": true,
  "type": "app.UICFNReplayTopTabSearchChildSearchId.CallSearchReplayIdApiFlow"
}

8:57:01 PM · type.find

{
  "h": 11,
  "static": true,
  "type": "app.UICFNReplayTopTabSearchChildSearchId.SearchItem"
}

8:56:57 PM · type.find

{
  "h": 10,
  "static": true,
  "type": "app.UICFNReplayTopTabSearchChildSearchId.FlowParam"
}

8:56:51 PM · type.find

{
  "h": 9,
  "static": true,
  "type": "app.UICFNReplayTopTabSearchChildSearchId"
}```
