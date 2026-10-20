# CFN menu-flow wrappers and the replay route enum (2026-10-19, TDB 71)

Raw op console: `type.find` + `object.describe` on the wrapper types found by `type.search`. `ReplaySearchIdRoute` values read with `field.get` in the listed order: EReplayMenu 1, EProfile 2, ERanking 3, EFightersList 4. `type.find` on the open generic `app.UIFlowCFNCommon.CallFollowApiFlow`1` returned null.

```
8:22:36 PM · type.find

{
  "h": 49,
  "static": true,
  "type": "app.UICFNReplaySearchResult.CallSearchReplayIdApiFlow"
}
8:22:59 PM · object.describe

{
  "fields": [
    {
      "name": "_IsUpdate",
      "offset": 40,
      "static": false,
      "type": "System.Boolean"
    }
  ],
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
      "name": "OnExit",
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
  "parent": "app.UIFlowAPI`1<app.UICFNReplaySearchResult.FlowParam>",
  "size": 41,
  "type": "app.UICFNReplaySearchResult.CallSearchReplayIdApiFlow",
  "valuetype": false
}

8:24:29 PM · object.describe

{
  "fields": [
    {
      "name": "DefaultSortType",
      "offset": 16,
      "static": true,
      "type": "app.network.api.Enum.ReplaySearchSortType"
    },
    {
      "name": "SEARCH_RESULT_MAX",
      "offset": 16,
      "static": true,
      "type": "System.UInt32"
    }
  ],
  "methods": [
    {
      "name": "Start",
      "params": [
        {
          "name": "param",
          "type": "app.UICFNReplaySearchResult.FlowParam"
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
  "type": "app.UICFNReplaySearchResult",
  "valuetype": false
}

8:24:15 PM · object.define

BridgeError: unknown op: object.define

8:23:54 PM · type.find

{
  "h": 50,
  "static": true,
  "type": "app.UICFNReplaySearchResult"
}

8:25:37 PM · object.describe

{
  "fields": [],
  "methods": [
    {
      "name": "Start",
      "params": [
        {
          "name": "param",
          "type": "app.UICFNFightersListTabSearchChildIdSearch.FlowParam"
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
  "type": "app.UICFNFightersListTabSearchChildIdSearch",
  "valuetype": false
}

8:25:34 PM · object.describe

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
    },
    {
      "name": "<OnCallApi>b__0_0",
      "params": [
        {
          "name": "result",
          "type": "app.network.api.HatoClientAPI.Component.PostFighterSearchShortIdOut"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<OnCallApi>b__0_1",
      "params": [
        {
          "name": "error",
          "type": "app.network.api.HatoClientAPI.Component.CommonErrorOutput"
        }
      ],
      "returns": "System.Void",
      "static": false
    }
  ],
  "parent": "app.UIFlowAPI`1<app.UICFNFightersListTabSearchChildIdSearch.FlowParam>",
  "size": 40,
  "type": "app.UICFNFightersListTabSearchChildIdSearch.CallSearchShortIdApiFlow",
  "valuetype": false
}

8:25:18 PM · type.find

{
  "h": 52,
  "static": true,
  "type": "app.UICFNFightersListTabSearchChildIdSearch"
}

8:25:08 PM · type.find

{
  "h": 51,
  "static": true,
  "type": "app.UICFNFightersListTabSearchChildIdSearch.CallSearchShortIdApiFlow"
}

8:26:02 PM · type.find

null

8:28:41 PM · field.get

4

8:28:29 PM · field.get

3

8:28:25 PM · field.get

2

8:28:11 PM · field.get

1

8:26:40 PM · object.describe

{
  "fields": [
    {
      "name": "value__",
      "offset": 16,
      "static": false,
      "type": "System.Int32"
    },
    {
      "name": "EReplayMenu",
      "offset": 16,
      "static": true,
      "type": "app.network.api.Enum.ReplaySearchIdRoute"
    },
    {
      "name": "EProfile",
      "offset": 16,
      "static": true,
      "type": "app.network.api.Enum.ReplaySearchIdRoute"
    },
    {
      "name": "ERanking",
      "offset": 16,
      "static": true,
      "type": "app.network.api.Enum.ReplaySearchIdRoute"
    },
    {
      "name": "EFightersList",
      "offset": 16,
      "static": true,
      "type": "app.network.api.Enum.ReplaySearchIdRoute"
    }
  ],
  "methods": [],
  "parent": "System.Enum",
  "size": 20,
  "type": "app.network.api.Enum.ReplaySearchIdRoute",
  "valuetype": true
}

8:26:26 PM · type.find

{
  "h": 53,
  "static": true,
  "type": "app.network.api.Enum.ReplaySearchIdRoute"
}```
