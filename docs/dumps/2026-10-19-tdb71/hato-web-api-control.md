# app.network.HatoWebApiControl — SF6 Steam, TDB 71, 2026-10-19

Reached as NetworkManager.<WebApi>k__BackingField.<Hato>k__BackingField. Raw object.describe output.

```

{
  "fields": [
    {
      "name": "NewChallengerRank",
      "offset": 80,
      "static": true,
      "type": "System.UInt32"
    },
    {
      "name": "UpdateLeagueParamWaitTime",
      "offset": 80,
      "static": true,
      "type": "System.Single"
    },
    {
      "name": "<Api>k__BackingField",
      "offset": 96,
      "static": false,
      "type": "app.network.api.HatoClientAPI.HatoClientAPI"
    },
    {
      "name": "<ShortId>k__BackingField",
      "offset": 104,
      "static": false,
      "type": "System.UInt32"
    },
    {
      "name": "<MannerGrade>k__BackingField",
      "offset": 108,
      "static": false,
      "type": "System.UInt32"
    },
    {
      "name": "<BannerInfo>k__BackingField",
      "offset": 112,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Component.CommonFighterBannerInfo"
    },
    {
      "name": "<ExamState>k__BackingField",
      "offset": 120,
      "static": false,
      "type": "app.network.api.HatoClientAPI.Component.CommonMatchingExamState"
    },
    {
      "name": "<IsMasterLeagueEnabled>k__BackingField",
      "offset": 128,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "<IsForceCrossPlayOff>k__BackingField",
      "offset": 129,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "SignedURL",
      "offset": 136,
      "static": false,
      "type": "System.String"
    },
    {
      "name": "MonthlyAvatarPointOld",
      "offset": 144,
      "static": false,
      "type": "System.Int64"
    },
    {
      "name": "MonthlyAvatarPoint",
      "offset": 152,
      "static": false,
      "type": "System.Int64"
    },
    {
      "name": "MonthlyAvatarPointReset",
      "offset": 160,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "LeagueParamList",
      "offset": 168,
      "static": false,
      "type": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonMatchingLeaguePoint>"
    },
    {
      "name": "LifenLeagueParamList",
      "offset": 176,
      "static": false,
      "type": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonRivalAiCharacterLeagueRank>"
    },
    {
      "name": "ConsecutiveWinList",
      "offset": 184,
      "static": false,
      "type": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonAuthLoginInfo.ConsecutiveWinsVal>"
    },
    {
      "name": "WarningMessageList",
      "offset": 192,
      "static": false,
      "type": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonAuthWarningMessage>"
    },
    {
      "name": "UpdateLeagueParamWaitTimeWork",
      "offset": 200,
      "static": false,
      "type": "System.Single"
    }
  ],
  "methods": [
    {
      "name": "get_Api",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.HatoClientAPI",
      "static": false
    },
    {
      "name": "set_Api",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.HatoClientAPI"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_ShortId",
      "params": [],
      "returns": "System.UInt32",
      "static": false
    },
    {
      "name": "set_ShortId",
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
      "name": "get_MannerGrade",
      "params": [],
      "returns": "System.UInt32",
      "static": false
    },
    {
      "name": "set_MannerGrade",
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
      "name": "get_ExamState",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Component.CommonMatchingExamState",
      "static": false
    },
    {
      "name": "set_ExamState",
      "params": [
        {
          "name": "value",
          "type": "app.network.api.HatoClientAPI.Component.CommonMatchingExamState"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_IsMasterLeagueEnabled",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "set_IsMasterLeagueEnabled",
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
      "name": "get_IsForceCrossPlayOff",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "set_IsForceCrossPlayOff",
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
      "name": "SetShortId",
      "params": [
        {
          "name": "shortId",
          "type": "System.UInt32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "SetMannerGrade",
      "params": [
        {
          "name": "mannerGrade",
          "type": "System.UInt32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "SetBannerInfo",
      "params": [
        {
          "name": "bannerInfo",
          "type": "app.network.api.HatoClientAPI.Component.CommonFighterBannerInfo"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "GetPlatformId",
      "params": [],
      "returns": "app.network.api.Enum.PlatformId",
      "static": false
    },
    {
      "name": "GetMainCircleName",
      "params": [],
      "returns": "System.String",
      "static": false
    },
    {
      "name": "GetMainCircleEmblem",
      "params": [],
      "returns": "app.network.api.HatoClientAPI.Component.CommonCircleEmblem",
      "static": false
    },
    {
      "name": "GetWarningMessageList",
      "params": [],
      "returns": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonAuthWarningMessage>",
      "static": false
    },
    {
      "name": "GetMainCircleLeaderShortId",
      "params": [],
      "returns": "System.UInt32",
      "static": false
    },
    {
      "name": "ReqeustUpdateLeagueParam",
      "params": [
        {
          "name": "callback",
          "type": "System.Action"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "SetLeagueParamList",
      "params": [
        {
          "name": "leagueParamList",
          "type": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonMatchingLeaguePoint>"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "GetLeagueParam",
      "params": [
        {
          "name": "fighterId",
          "type": "System.Int32"
        }
      ],
      "returns": "app.network.api.HatoClientAPI.Component.CommonMatchingLeaguePoint",
      "static": false
    },
    {
      "name": "GetLeagueParamListCopy",
      "params": [],
      "returns": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonMatchingLeaguePoint>",
      "static": false
    },
    {
      "name": "GetLeagueRank",
      "params": [
        {
          "name": "fighterId",
          "type": "System.Int32"
        }
      ],
      "returns": "System.UInt32",
      "static": false
    },
    {
      "name": "GetLeaguePoint",
      "params": [
        {
          "name": "fighterId",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "SetLifenLeagueParamList",
      "params": [
        {
          "name": "leagueParamList",
          "type": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonRivalAiCharacterLeagueRank>"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "SetLifenLeagueParam",
      "params": [
        {
          "name": "leagueParam",
          "type": "app.network.api.HatoClientAPI.Component.CommonRivalAiCharacterLeagueRank"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "GetLifenLeagueParam",
      "params": [
        {
          "name": "fighterId",
          "type": "System.Int32"
        }
      ],
      "returns": "app.network.api.HatoClientAPI.Component.CommonRivalAiCharacterLeagueRank",
      "static": false
    },
    {
      "name": "GetLifenLeagueParamListCopy",
      "params": [],
      "returns": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonRivalAiCharacterLeagueRank>",
      "static": false
    },
    {
      "name": "GetLifenLeagueRank",
      "params": [
        {
          "name": "fighterId",
          "type": "System.Int32"
        }
      ],
      "returns": "System.UInt32",
      "static": false
    },
    {
      "name": "SetConsecutiveWins",
      "params": [
        {
          "name": "list",
          "type": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonAuthLoginInfo.ConsecutiveWinsVal>"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "SetWarningMessageList",
      "params": [
        {
          "name": "list",
          "type": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.CommonAuthWarningMessage>"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "SetConsecutiveWins",
      "params": [
        {
          "name": "list",
          "type": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.PostMatchingFightEndOut.ConsecutiveWinsVal>"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "SetConsecutiveWins",
      "params": [
        {
          "name": "list",
          "type": "System.Collections.Generic.List`1<app.network.api.HatoClientAPI.Component.PostMatchingEndCpuExamOut.ConsecutiveWinsVal>"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "GetConsecutiveWin",
      "params": [
        {
          "name": "matchingType",
          "type": "app.network.api.Enum.MatchingType"
        },
        {
          "name": "fighterId",
          "type": "System.UInt32"
        }
      ],
      "returns": "System.UInt32",
      "static": false
    },
    {
      "name": "IsDecideExamRank",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "GetFighterExamInfo",
      "params": [
        {
          "name": "fighterId",
          "type": "System.Int32"
        }
      ],
      "returns": "app.network.api.HatoClientAPI.Component.CommonMatchingExamInfo",
      "static": false
    },
    {
      "name": "IsNeedExamMatch",
      "params": [
        {
          "name": "fighterId",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "IsNowExamMatch",
      "params": [
        {
          "name": "fighterId",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "IsExamCpuBattle",
      "params": [
        {
          "name": "fighterId",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "SetExamState",
      "params": [
        {
          "name": "examState",
          "type": "app.network.api.HatoClientAPI.Component.CommonMatchingExamState"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "SetFirstExamState",
      "params": [
        {
          "name": "fighterId",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "SetExamRank",
      "params": [
        {
          "name": "selectRank",
          "type": "app.network.api.Enum.MatchingExamRank"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "SetMasterLeagueEnabled",
      "params": [
        {
          "name": "enabled",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "SetForceCrossPlayOffFlag",
      "params": [
        {
          "name": "flag",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "SetSignedURL",
      "params": [
        {
          "name": "url",
          "type": "System.String"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "SetAvatarRandomMatchPoint",
      "params": [
        {
          "name": "point",
          "type": "System.Int64"
        },
        {
          "name": "isReset",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "doSetup",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "update",
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
  "parent": "app.network.WebApiControlBase",
  "size": 208,
  "type": "app.network.HatoWebApiControl",
  "valuetype": false
}


{
  "h": 1105,
  "type": "app.network.HatoWebApiControl"
}
```
