# app.network.api.HatoClientAPI.HatoClientAPI — SF6 Steam, TDB 71, 2026-10-19

The CFN API client: one field per endpoint group. Raw object.describe output.

```

{
  "fields": [
    {
      "name": "<auth>k__BackingField",
      "offset": 16,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Api.Auth"
    },
    {
      "name": "<chat>k__BackingField",
      "offset": 24,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Api.Chat"
    },
    {
      "name": "<circle>k__BackingField",
      "offset": 32,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Api.Circle"
    },
    {
      "name": "<debug>k__BackingField",
      "offset": 40,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Api.Debug"
    },
    {
      "name": "<fighter>k__BackingField",
      "offset": 48,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Api.Fighter"
    },
    {
      "name": "<fighters_list>k__BackingField",
      "offset": 56,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Api.FightersList"
    },
    {
      "name": "<inventory>k__BackingField",
      "offset": 64,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Api.Inventory"
    },
    {
      "name": "<mail>k__BackingField",
      "offset": 72,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Api.Mail"
    },
    {
      "name": "<mame>k__BackingField",
      "offset": 80,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Api.Mame"
    },
    {
      "name": "<matching>k__BackingField",
      "offset": 88,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Api.Matching"
    },
    {
      "name": "<mode_select>k__BackingField",
      "offset": 96,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Api.ModeSelect"
    },
    {
      "name": "<multi_menu>k__BackingField",
      "offset": 104,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Api.MultiMenu"
    },
    {
      "name": "<ogym>k__BackingField",
      "offset": 112,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Api.Ogym"
    },
    {
      "name": "<ranking>k__BackingField",
      "offset": 120,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Api.Ranking"
    },
    {
      "name": "<replay>k__BackingField",
      "offset": 128,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Api.Replay"
    },
    {
      "name": "<rewards>k__BackingField",
      "offset": 136,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Api.Rewards"
    },
    {
      "name": "<rival_ai>k__BackingField",
      "offset": 144,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Api.RivalAi"
    },
    {
      "name": "<shop>k__BackingField",
      "offset": 152,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Api.Shop"
    },
    {
      "name": "<sys>k__BackingField",
      "offset": 160,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Api.Sys"
    }
  ],
  "methods": [
    {
      "name": ".ctor",
      "params": [
        {
          "name": "controller",
          "type": "app.network.WebApiClient"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_auth",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Api.Auth",
      "static": false
    },
    {
      "name": "set_auth",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Api.Auth"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_chat",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Api.Chat",
      "static": false
    },
    {
      "name": "set_chat",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Api.Chat"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_circle",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Api.Circle",
      "static": false
    },
    {
      "name": "set_circle",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Api.Circle"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_debug",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Api.Debug",
      "static": false
    },
    {
      "name": "set_debug",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Api.Debug"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_fighter",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Api.Fighter",
      "static": false
    },
    {
      "name": "set_fighter",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Api.Fighter"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_fighters_list",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Api.FightersList",
      "static": false
    },
    {
      "name": "set_fighters_list",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Api.FightersList"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_inventory",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Api.Inventory",
      "static": false
    },
    {
      "name": "set_inventory",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Api.Inventory"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_mail",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Api.Mail",
      "static": false
    },
    {
      "name": "set_mail",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Api.Mail"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_mame",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Api.Mame",
      "static": false
    },
    {
      "name": "set_mame",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Api.Mame"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_matching",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Api.Matching",
      "static": false
    },
    {
      "name": "set_matching",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Api.Matching"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_mode_select",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Api.ModeSelect",
      "static": false
    },
    {
      "name": "set_mode_select",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Api.ModeSelect"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_multi_menu",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Api.MultiMenu",
      "static": false
    },
    {
      "name": "set_multi_menu",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Api.MultiMenu"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_ogym",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Api.Ogym",
      "static": false
    },
    {
      "name": "set_ogym",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Api.Ogym"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_ranking",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Api.Ranking",
      "static": false
    },
    {
      "name": "set_ranking",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Api.Ranking"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_replay",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Api.Replay",
      "static": false
    },
    {
      "name": "set_replay",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Api.Replay"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_rewards",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Api.Rewards",
      "static": false
    },
    {
      "name": "set_rewards",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Api.Rewards"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_rival_ai",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Api.RivalAi",
      "static": false
    },
    {
      "name": "set_rival_ai",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Api.RivalAi"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_shop",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Api.Shop",
      "static": false
    },
    {
      "name": "set_shop",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Api.Shop"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_sys",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Api.Sys",
      "static": false
    },
    {
      "name": "set_sys",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Api.Sys"
        }
      ],
      "returns": "System.Void",
      "static": false
    }
  ],
  "parent": "System.Object",
  "size": 168,
  "type": "app.network.api.HatoClientAPI.HatoClientAPI",
  "valuetype": false
}


{
  "h": 1106,
  "type": "app.network.api.HatoClientAPI.HatoClientAPI"
}
```
