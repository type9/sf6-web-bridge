# `gBattle` statics and `nBattle.cPlayer` (2026-10-19, TDB 71, Training Mode)

`type.find gBattle` → `field.get Player` (`nBattle.sPlayer`), `Team` (`app.BattleTeam`), `Training` (`app.TrainingInput`); `sPlayer.mcPlayer` is `nBattle.cPlayer[6]`; `object.describe` of element 0 below. `cPlayer` derives from `nBattle.cWork`, whose own fields (offsets below 432) are not in this dump.

```
8:33:33 PM · object.describe

{
  "fields": [
    {
      "name": "Methods",
      "offset": 16,
      "static": true,
      "type": "nBattle.cWork.Methods"
    },
    {
      "name": "NRM_NUKI_CNT",
      "offset": 16,
      "static": true,
      "type": "System.SByte"
    },
    {
      "name": "UKEM_NUKI_CNT",
      "offset": 16,
      "static": true,
      "type": "System.SByte"
    },
    {
      "name": "CATCH_NUKI_CNT",
      "offset": 16,
      "static": true,
      "type": "System.SByte"
    },
    {
      "name": "FRONT_ATTACK",
      "offset": 16,
      "static": true,
      "type": "System.Boolean"
    },
    {
      "name": "BACK_ATTACK",
      "offset": 16,
      "static": true,
      "type": "System.Boolean"
    },
    {
      "name": "rl_dir",
      "offset": 432,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "cmd_dir",
      "offset": 433,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "cmd_side",
      "offset": 434,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "exp_rl_dir",
      "offset": 435,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "ne_to_ne_flag",
      "offset": 436,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "ne_to_stand_flag",
      "offset": 437,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "double_end_flag",
      "offset": 438,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "double_disp_ON",
      "offset": 439,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "double_disp_OFF",
      "offset": 440,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "move_act_init",
      "offset": 441,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "death_flag",
      "offset": 442,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "erase_flag",
      "offset": 443,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "piyo_act_flag",
      "offset": 444,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "piyo_now_flag",
      "offset": 445,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "z_move_free",
      "offset": 446,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "kuzure_dm_flag",
      "offset": 447,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "dummy_work",
      "offset": 448,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "auto_guard_flag",
      "offset": 449,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "pl_range_out",
      "offset": 450,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "high_jump_flag",
      "offset": 451,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "counter_dm_flag",
      "offset": 452,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "counter_fw_flag",
      "offset": 453,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "danger",
      "offset": 454,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "shaky_dm_flag",
      "offset": 455,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "just_dm_flag",
      "offset": 456,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "easy_dm_flag",
      "offset": 457,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "next_to_normal",
      "offset": 458,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "zone_dm_flag",
      "offset": 459,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "zone_nage_flag",
      "offset": 460,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "dying_flag",
      "offset": 461,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "auto_pilot",
      "offset": 462,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "guts_flag",
      "offset": 463,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "piyo_reset_flag",
      "offset": 464,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "rush_start_flag",
      "offset": 465,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "act_st",
      "offset": 466,
      "static": false,
      "type": "nBattle.ACT_ST.ID"
    },
    {
      "name": "act_st_old",
      "offset": 467,
      "static": false,
      "type": "nBattle.ACT_ST.ID"
    },
    {
      "name": "act_dir",
      "offset": 468,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "move_dir",
      "offset": 469,
      "static": false,
      "type": "nBattle.DASH_DIR"
    },
    {
      "name": "jump_com_cnt",
      "offset": 470,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "jump_act_cnt",
      "offset": 471,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "sjump_elps",
      "offset": 472,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "wjump_cnt",
      "offset": 473,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "pgrd_time",
      "offset": 474,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "guard_time",
      "offset": 475,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "guard_pose_req",
      "offset": 476,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "guard_st",
      "offset": 478,
      "static": false,
      "type": "nBattle.nHit.GUARD_ST"
    },
    {
      "name": "dmg_attr",
      "offset": 480,
      "static": false,
      "type": "nBattle.nHit.DMG_ATTR"
    },
    {
      "name": "jimen_bound_bit",
      "offset": 482,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "wall_bound_bit",
      "offset": 483,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "impact_bound_bit",
      "offset": 484,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "slide_dm_bit",
      "offset": 485,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "mot_variation",
      "offset": 486,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "bound_height",
      "offset": 487,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "piyo_point",
      "offset": 488,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "sleep_time",
      "offset": 490,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "catch_flag",
      "offset": 492,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "adv_no_back",
      "offset": 493,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "multi_target",
      "offset": 494,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "pincer_atck",
      "offset": 495,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "sukari_time",
      "offset": 496,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "catch_muteki",
      "offset": 497,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "lock_hosei_cnt",
      "offset": 498,
      "static": false,
      "type": "System.UInt16"
    },
    {
      "name": "no_hit_time",
      "offset": 500,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "muteki_time",
      "offset": 501,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "no_super_time",
      "offset": 502,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "auto_gd_time",
      "offset": 503,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "force_no_gd_time",
      "offset": 504,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "no_target_time",
      "offset": 505,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "no_target_change",
      "offset": 506,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "pincer_time",
      "offset": 507,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "no_shaky_time",
      "offset": 508,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "no_touch_time",
      "offset": 509,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "cmd_ng_time",
      "offset": 510,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "pl_dash_wait",
      "offset": 511,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "pl_cmd_wait",
      "offset": 512,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "pl_cmd_keep",
      "offset": 513,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "no_escape_time",
      "offset": 514,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "land_suki_flag",
      "offset": 515,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "scr_hosei_time",
      "offset": 516,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "no_push_time",
      "offset": 517,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "pl_nagerare_type",
      "offset": 518,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "pose_st",
      "offset": 519,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "pl_jump_st",
      "offset": 520,
      "static": false,
      "type": "nBattle.JUMP_ST"
    },
    {
      "name": "scr_hosei_bit",
      "offset": 521,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "contact_L_bit",
      "offset": 522,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "contact_R_bit",
      "offset": 523,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "ruthless_bit",
      "offset": 524,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "wall_hit_bit",
      "offset": 525,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "sp_speed",
      "offset": 526,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "fly",
      "offset": 528,
      "static": false,
      "type": "nBattle.FLYING"
    },
    {
      "name": "trans_offset",
      "offset": 532,
      "static": false,
      "type": "System.Single"
    },
    {
      "name": "cam_scr_pos",
      "offset": 536,
      "static": false,
      "type": "via.sfix"
    },
    {
      "name": "vs_player",
      "offset": 544,
      "static": false,
      "type": "nBattle.cPlayer"
    },
    {
      "name": "catch_shl_add",
      "offset": 552,
      "static": false,
      "type": "nBattle.cWork"
    },
    {
      "name": "gard_combo_cnt",
      "offset": 560,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "dgard_combo_cnt",
      "offset": 561,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "parry_combo_cnt",
      "offset": 562,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "reversal_time",
      "offset": 563,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "grd_base",
      "offset": 564,
      "static": false,
      "type": "nBattle.ACT_ID"
    },
    {
      "name": "damage_speed",
      "offset": 568,
      "static": false,
      "type": "via.Sfix2"
    },
    {
      "name": "vector_zuri",
      "offset": 576,
      "static": false,
      "type": "nBattle.ZURI"
    },
    {
      "name": "damage_cond",
      "offset": 584,
      "static": false,
      "type": "nBattle.DMG_CONDITION"
    },
    {
      "name": "damage_sleep",
      "offset": 588,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "damage_type",
      "offset": 590,
      "static": false,
      "type": "CharacterAsset.DamageType"
    },
    {
      "name": "zuri_pl_bit",
      "offset": 591,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "damage_pl_bit",
      "offset": 592,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "damage_info",
      "offset": 596,
      "static": false,
      "type": "nBattle.DMG_INFO"
    },
    {
      "name": "to_go_down",
      "offset": 616,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "wall_hit_flag",
      "offset": 617,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "aerial_finish",
      "offset": 618,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "aerial_release",
      "offset": 619,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "floor_hit_flag",
      "offset": 620,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "nage_tataki_f",
      "offset": 621,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "damage_back",
      "offset": 622,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "damage_back_old",
      "offset": 623,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "sp_armor",
      "offset": 624,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "incapacitated",
      "offset": 625,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "aerial_begin",
      "offset": 626,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "roll_time",
      "offset": 627,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "damage_time",
      "offset": 628,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "nagerare_cnt",
      "offset": 629,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "world_param",
      "offset": 630,
      "static": false,
      "type": "nBattle.World.Req"
    },
    {
      "name": "combo_scale",
      "offset": 636,
      "static": false,
      "type": "nBattle.COMBO_SCALE"
    },
    {
      "name": "pgrd_pos",
      "offset": 640,
      "static": false,
      "type": "via.Sfix2"
    },
    {
      "name": "cam_pos",
      "offset": 648,
      "static": false,
      "type": "via.Sfix2"
    },
    {
      "name": "act_root",
      "offset": 656,
      "static": false,
      "type": "via.Sfix2"
    },
    {
      "name": "pl_touch_flag",
      "offset": 664,
      "static": false,
      "type": "nBattle.TOUCH.FLAG"
    },
    {
      "name": "pl_touch_st",
      "offset": 668,
      "static": false,
      "type": "nBattle.TOUCH.FLAG"
    },
    {
      "name": "pl_touch_act",
      "offset": 672,
      "static": false,
      "type": "nBattle.TOUCH.ACT"
    },
    {
      "name": "partner_flag",
      "offset": 676,
      "static": false,
      "type": "nBattle.PARTNER_ID"
    },
    {
      "name": "combo_cnt",
      "offset": 678,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "combo_dm_cnt",
      "offset": 680,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "combo_dm_air",
      "offset": 682,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "combo_air",
      "offset": 684,
      "static": false,
      "type": "nBattle.nHit.Combo"
    },
    {
      "name": "combo_air_old",
      "offset": 685,
      "static": false,
      "type": "nBattle.nHit.Combo"
    },
    {
      "name": "combo_aerial",
      "offset": 686,
      "static": false,
      "type": "nBattle.nHit.Combo"
    },
    {
      "name": "resist_cnt",
      "offset": 687,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "combo_sp",
      "offset": 688,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "combo_assist",
      "offset": 689,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "combo_reset_flag",
      "offset": 690,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "combo_hold_flag",
      "offset": 691,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "nage_combo_flag",
      "offset": 692,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "shl_catch_cnt",
      "offset": 693,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "kezu_stand_cnt",
      "offset": 694,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "counter_trg",
      "offset": 695,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "trade_dm_flag",
      "offset": 696,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "step_dm_flag",
      "offset": 697,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "combo_sp_rate",
      "offset": 698,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "trigger_notice",
      "offset": 699,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "used_type_bit",
      "offset": 700,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "throw_tech_no",
      "offset": 701,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "input_mask_timer",
      "offset": 702,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "adv_guard",
      "offset": 704,
      "static": false,
      "type": "nBattle.AG_ZURI"
    },
    {
      "name": "vs_adv_zuri",
      "offset": 720,
      "static": false,
      "type": "nBattle.VS_ZURI"
    },
    {
      "name": "vs_vec_zuri",
      "offset": 736,
      "static": false,
      "type": "nBattle.VS_ZURI"
    },
    {
      "name": "vs_tai_zuri",
      "offset": 752,
      "static": false,
      "type": "nBattle.VS_ZURI"
    },
    {
      "name": "draw_zuri",
      "offset": 768,
      "static": false,
      "type": "nBattle.ZURI"
    },
    {
      "name": "dm_taisei",
      "offset": 776,
      "static": false,
      "type": "nBattle.ARMOR"
    },
    {
      "name": "inertia",
      "offset": 792,
      "static": false,
      "type": "nBattle.INERTIA"
    },
    {
      "name": "vs_distance",
      "offset": 804,
      "static": false,
      "type": "via.sfix"
    },
    {
      "name": "kizetsu_timer",
      "offset": 808,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "touch_suki_timer",
      "offset": 810,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "pl_assist_flag",
      "offset": 812,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "shell_total",
      "offset": 814,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "calc_buff_x",
      "offset": 816,
      "static": false,
      "type": "via.sfix"
    },
    {
      "name": "calc_buff_y",
      "offset": 820,
      "static": false,
      "type": "via.sfix"
    },
    {
      "name": "mAdjustRotY",
      "offset": 824,
      "static": false,
      "type": "System.Single"
    },
    {
      "name": "mCheckInfo",
      "offset": 832,
      "static": false,
      "type": "Command.CommandCheckInfo"
    },
    {
      "name": "mSAReserved",
      "offset": 840,
      "static": false,
      "type": "System.UInt16"
    },
    {
      "name": "mSABuff",
      "offset": 842,
      "static": false,
      "type": "System.UInt16"
    },
    {
      "name": "mDRBuff",
      "offset": 844,
      "static": false,
      "type": "nBattle.DR_BUFF"
    },
    {
      "name": "mReserveAct",
      "offset": 848,
      "static": false,
      "type": "nBattle.ACT_ID"
    },
    {
      "name": "style_end_act",
      "offset": 856,
      "static": false,
      "type": "System.UInt64"
    },
    {
      "name": "style_wait_act",
      "offset": 864,
      "static": false,
      "type": "System.UInt64"
    },
    {
      "name": "style_timer",
      "offset": 872,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "style_timer0",
      "offset": 874,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "style_end_id",
      "offset": 876,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "style_ng_act",
      "offset": 878,
      "static": false,
      "type": "System.UInt16"
    },
    {
      "name": "style_old",
      "offset": 880,
      "static": false,
      "type": "System.UInt16"
    },
    {
      "name": "style_ability",
      "offset": 884,
      "static": false,
      "type": "nBattle.STYLE.ABILITY.FLAG"
    },
    {
      "name": "style_hosei_atk",
      "offset": 888,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "style_hosei_dmg",
      "offset": 889,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "style_regen_vital",
      "offset": 890,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "style_hosei_sup",
      "offset": 891,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "style_fc_rcv_inc",
      "offset": 892,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "style_fc_rcv_nom",
      "offset": 894,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "style_fc_rcv_inA",
      "offset": 896,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "style_fc_rcv_nmA",
      "offset": 898,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "regen_vital",
      "offset": 900,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "style_regen_super",
      "offset": 901,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "pl_input_new",
      "offset": 902,
      "static": false,
      "type": "System.UInt16"
    },
    {
      "name": "pl_input_old",
      "offset": 904,
      "static": false,
      "type": "System.UInt16"
    },
    {
      "name": "pl_input_old1",
      "offset": 906,
      "static": false,
      "type": "System.UInt16"
    },
    {
      "name": "pl_input_now",
      "offset": 908,
      "static": false,
      "type": "System.UInt16"
    },
    {
      "name": "pl_sw_new",
      "offset": 910,
      "static": false,
      "type": "System.UInt16"
    },
    {
      "name": "pl_sw_old",
      "offset": 912,
      "static": false,
      "type": "System.UInt16"
    },
    {
      "name": "pl_sw_now",
      "offset": 914,
      "static": false,
      "type": "System.UInt16"
    },
    {
      "name": "pl_sw_parry",
      "offset": 916,
      "static": false,
      "type": "nBattle.PARRY.INPUT"
    },
    {
      "name": "pl_sw_throw",
      "offset": 928,
      "static": false,
      "type": "nBattle.THROW.INPUT"
    },
    {
      "name": "pl_sw_guard",
      "offset": 944,
      "static": false,
      "type": "System.UInt16"
    },
    {
      "name": "blk_cmd",
      "offset": 952,
      "static": false,
      "type": "nBattle.BLOCKING[]"
    },
    {
      "name": "pl_cmd_buff",
      "offset": 960,
      "static": false,
      "type": "nBattle.NORMAL_CMD"
    },
    {
      "name": "pl_cmd_now",
      "offset": 962,
      "static": false,
      "type": "nBattle.NORMAL_CMD"
    },
    {
      "name": "pl_touch_tame",
      "offset": 964,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "parry_ok_time",
      "offset": 965,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "parry_ng_time",
      "offset": 966,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "avoid_ok_time",
      "offset": 967,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "back_target_time",
      "offset": 968,
      "static": false,
      "type": "System.SByte"
    },
    {
      "name": "sup_hosei_rate",
      "offset": 969,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "fc_hosei_rate",
      "offset": 970,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "sp_armor_timer",
      "offset": 972,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "sp_turbo",
      "offset": 976,
      "static": false,
      "type": "nBattle.TURBO"
    },
    {
      "name": "healing_wait",
      "offset": 984,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "revive_vital",
      "offset": 986,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "reserve_vital",
      "offset": 988,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "pl_cmn1_flags",
      "offset": 992,
      "static": false,
      "type": "nBattle.PL_CMN1.FLAG"
    },
    {
      "name": "comb_id_buff",
      "offset": 1000,
      "static": false,
      "type": "System.UInt16[]"
    },
    {
      "name": "master_assist_timer",
      "offset": 1008,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "master_assist_total_time",
      "offset": 1010,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "vital_max",
      "offset": 1012,
      "static": false,
      "type": "System.Int32"
    },
    {
      "name": "vital_new",
      "offset": 1016,
      "static": false,
      "type": "System.Int32"
    },
    {
      "name": "vital_old",
      "offset": 1020,
      "static": false,
      "type": "System.Int32"
    },
    {
      "name": "heal_new",
      "offset": 1024,
      "static": false,
      "type": "System.Int32"
    },
    {
      "name": "focus_max",
      "offset": 1028,
      "static": false,
      "type": "System.Int32"
    },
    {
      "name": "focus_new",
      "offset": 1032,
      "static": false,
      "type": "System.Int32"
    },
    {
      "name": "focus_wait",
      "offset": 1036,
      "static": false,
      "type": "System.Int16"
    },
    {
      "name": "partner_id",
      "offset": 1038,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "vital_share",
      "offset": 1039,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "free_to_move",
      "offset": 1040,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "die_out",
      "offset": 1041,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "coop_flag",
      "offset": 1042,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "die_getout_ctrl",
      "offset": 1043,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "minion_flag",
      "offset": 1044,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "master_assist_flag",
      "offset": 1045,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "bench_start",
      "offset": 1046,
      "static": false,
      "type": "System.Boolean"
    },
    {
      "name": "pl_weight",
      "offset": 1047,
      "static": false,
      "type": "nBattle.PL_WEIGHT"
    },
    {
      "name": "type_pri",
      "offset": 1048,
      "static": false,
      "type": "System.Byte"
    },
    {
      "name": "jimen_y",
      "offset": 1052,
      "static": false,
      "type": "via.sfix"
    },
    {
      "name": "mpTeam",
      "offset": 1056,
      "static": false,
      "type": "app.cTeam"
    },
    {
      "name": "mpCamera",
      "offset": 1064,
      "static": false,
      "type": "nBattle.cCameraWork"
    },
    {
      "name": "pDmgHitDT",
      "offset": 1072,
      "static": false,
      "type": "nBattle.HIT_DT"
    },
    {
      "name": "pDmgHitDTs",
      "offset": 1080,
      "static": false,
      "type": "nBattle.HIT_DT_TBL"
    },
    {
      "name": "mpPlData",
      "offset": 1088,
      "static": false,
      "type": "CharacterAsset.PersonalData"
    },
    {
      "name": "FLY_CEIL",
      "offset": 24,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "FLY_FLOOR",
      "offset": 28,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "fly_char_tbl",
      "offset": 32,
      "static": true,
      "type": "nBattle.ACT_ID[]"
    },
    {
      "name": "fly_end_tbl",
      "offset": 40,
      "static": true,
      "type": "nBattle.ACT_ID[]"
    },
    {
      "name": "_sin000",
      "offset": 16,
      "static": true,
      "type": "System.Int64"
    },
    {
      "name": "_sin045",
      "offset": 16,
      "static": true,
      "type": "System.Int64"
    },
    {
      "name": "_sin090",
      "offset": 16,
      "static": true,
      "type": "System.Int64"
    },
    {
      "name": "_sin135",
      "offset": 16,
      "static": true,
      "type": "System.Int64"
    },
    {
      "name": "_sin180",
      "offset": 16,
      "static": true,
      "type": "System.Int64"
    },
    {
      "name": "_sin225",
      "offset": 16,
      "static": true,
      "type": "System.Int64"
    },
    {
      "name": "_sin270",
      "offset": 16,
      "static": true,
      "type": "System.Int64"
    },
    {
      "name": "_sin315",
      "offset": 16,
      "static": true,
      "type": "System.Int64"
    },
    {
      "name": "_cos000",
      "offset": 16,
      "static": true,
      "type": "System.Int64"
    },
    {
      "name": "_cos045",
      "offset": 16,
      "static": true,
      "type": "System.Int64"
    },
    {
      "name": "_cos090",
      "offset": 16,
      "static": true,
      "type": "System.Int64"
    },
    {
      "name": "_cos135",
      "offset": 16,
      "static": true,
      "type": "System.Int64"
    },
    {
      "name": "_cos180",
      "offset": 16,
      "static": true,
      "type": "System.Int64"
    },
    {
      "name": "_cos225",
      "offset": 16,
      "static": true,
      "type": "System.Int64"
    },
    {
      "name": "_cos270",
      "offset": 16,
      "static": true,
      "type": "System.Int64"
    },
    {
      "name": "_cos315",
      "offset": 16,
      "static": true,
      "type": "System.Int64"
    },
    {
      "name": "fly_dash_rate",
      "offset": 48,
      "static": true,
      "type": "System.Int64[,]"
    },
    {
      "name": "kdash_act_tbl",
      "offset": 56,
      "static": true,
      "type": "nBattle.ACT_ID[]"
    },
    {
      "name": "kdash_dir_tbl",
      "offset": 64,
      "static": true,
      "type": "System.SByte[]"
    },
    {
      "name": "THROW_TECH_HOLD",
      "offset": 16,
      "static": true,
      "type": "System.SByte"
    },
    {
      "name": "THROW_TECH_END",
      "offset": 16,
      "static": true,
      "type": "System.SByte"
    },
    {
      "name": "THROW_TECH_CK",
      "offset": 16,
      "static": true,
      "type": "System.SByte"
    },
    {
      "name": "THROW_TECH_CK1",
      "offset": 16,
      "static": true,
      "type": "System.SByte"
    },
    {
      "name": "THROW_TECH_OK",
      "offset": 16,
      "static": true,
      "type": "System.SByte"
    },
    {
      "name": "THROW_TECH_AUTO",
      "offset": 16,
      "static": true,
      "type": "System.SByte"
    },
    {
      "name": "CK_DEFER",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "CK_DEF_EZ",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "CK_AUTO",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "CK_ASSIST",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "CK_EASY",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "CK_NORMAL",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "blk_input",
      "offset": 72,
      "static": true,
      "type": "nBattle.BLOCKING_PARAM[]"
    },
    {
      "name": "damage_vec_reverse",
      "offset": 80,
      "static": true,
      "type": "System.Int32[]"
    },
    {
      "name": "VEC_090",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "VEC_045",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "VEC_000",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "VEC_m45",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "VEC_m90",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "VEC_BAK",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "BAK_XXX",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "BAK_m90",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "blow_offset",
      "offset": 88,
      "static": true,
      "type": "System.Int32[,]"
    },
    {
      "name": "blow_fix_dir",
      "offset": 96,
      "static": true,
      "type": "nBattle.nHit.VEC[]"
    },
    {
      "name": "nage_cnt_tbl",
      "offset": 16,
      "static": true,
      "type": "System.UInt64"
    },
    {
      "name": "atck_sp_act_tbl",
      "offset": 16,
      "static": true,
      "type": "System.UInt64"
    },
    {
      "name": "dm_info_tbl",
      "offset": 104,
      "static": true,
      "type": "nBattle.DMG_DATA[]"
    },
    {
      "name": "OFS_STR_L",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "OFS_STR_M",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "OFS_STR_H",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "OFS_STR_C",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "OFS_STR_NUM",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "OFS_STD_HI",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "OFS_STD_MID",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "OFS_STD_LOW",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "OFS_CRO_HI",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "OFS_CRO_LOW",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "GND_DMG_NUM",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "dm_ground_tbl",
      "offset": 112,
      "static": true,
      "type": "nBattle.ACT_ID[]"
    },
    {
      "name": "dm_beatdown_tbl",
      "offset": 120,
      "static": true,
      "type": "nBattle.ACT_ID[]"
    },
    {
      "name": "dm_upper_tbl",
      "offset": 128,
      "static": true,
      "type": "nBattle.ACT_ID[]"
    },
    {
      "name": "LEVER_NUM",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "input_data",
      "offset": 136,
      "static": true,
      "type": "System.UInt32[]"
    },
    {
      "name": "guard_low_bit",
      "offset": 144,
      "static": true,
      "type": "System.Int32[]"
    },
    {
      "name": "TATAKI_HEIGHT",
      "offset": 152,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "POISON_TIME_DEF",
      "offset": 16,
      "static": true,
      "type": "System.Int16"
    },
    {
      "name": "P_HAND_TIME_DEF",
      "offset": 16,
      "static": true,
      "type": "System.Int16"
    },
    {
      "name": "GRD_STOP_H",
      "offset": 16,
      "static": true,
      "type": "System.SByte"
    },
    {
      "name": "GRD_STOP_M",
      "offset": 16,
      "static": true,
      "type": "System.SByte"
    },
    {
      "name": "GRD_STOP_L",
      "offset": 16,
      "static": true,
      "type": "System.SByte"
    },
    {
      "name": "tri_jump_hxz",
      "offset": 156,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "tri_jump_hyz",
      "offset": 160,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "tri_jump_hyg",
      "offset": 164,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "tri_jump_mxz",
      "offset": 168,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "tri_jump_myz",
      "offset": 172,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "tri_jump_myg",
      "offset": 176,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "LimitSpeedX_SJumpF",
      "offset": 180,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "LimitSpeedX_SJumpB",
      "offset": 184,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "Adjust_SJump_VF",
      "offset": 188,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "Adjust_SJump_VB",
      "offset": 192,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "Adjust_SJump_FF",
      "offset": 196,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "Adjust_SJump_FB",
      "offset": 200,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "Adjust_SJump_BF",
      "offset": 204,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "Adjust_SJump_BB",
      "offset": 208,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "DownAccel_SJump",
      "offset": 212,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "ASSIST_PL_ADJ_X",
      "offset": 216,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "ASSIST_PL_ADJ_Y",
      "offset": 220,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "ASSIST_PL_TIME",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "MINION_PL_ADJ_X",
      "offset": 224,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "MINION_PL_ADJ_Y",
      "offset": 228,
      "static": true,
      "type": "via.sfix"
    },
    {
      "name": "MINION_PL_TIME",
      "offset": 16,
      "static": true,
      "type": "System.Int32"
    },
    {
      "name": "pl_norm_tbl",
      "offset": 1096,
      "static": false,
      "type": "nBattle.cPlayer.Methods_vv[]"
    },
    {
      "name": "pl_act_tbl",
      "offset": 1104,
      "static": false,
      "type": "nBattle.cPlayer.Methods_vv[]"
    },
    {
      "name": "dm_jump_tbl",
      "offset": 1112,
      "static": false,
      "type": "nBattle.cPlayer.Methods_vw[,]"
    },
    {
      "name": "dm_type_tbl",
      "offset": 1120,
      "static": false,
      "type": "nBattle.cPlayer.Methods_vv[]"
    },
    {
      "name": "TOUCH_JMP_TIME",
      "offset": 16,
      "static": true,
      "type": "System.Single"
    },
    {
      "name": "TOUCH_JMP_TIME0",
      "offset": 16,
      "static": true,
      "type": "System.Single"
    },
    {
      "name": "TOUCH_JMP_TIME1",
      "offset": 16,
      "static": true,
      "type": "System.Single"
    },
    {
      "name": "TOUCH_JMP_TIME2",
      "offset": 16,
      "static": true,
      "type": "System.Single"
    }
  ],
  "methods": [
    {
      "name": ".ctor",
      "params": [
        {
          "name": "isEntity",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "Dispose",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "clear",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_common0_clear",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_common0_init",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_common1_clear",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_common1_init",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_common2_clear",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_common2_init",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "base_work_init",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_comn_work_clear",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_work_clear",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "getVitalNew",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "getVitalOld",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "getHealNew",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "getVitalMax",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "setVitalNew",
      "params": [
        {
          "name": "val",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "setVitalOld",
      "params": [
        {
          "name": "val",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "setHealNew",
      "params": [
        {
          "name": "val",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "setVitalMax",
      "params": [
        {
          "name": "val",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "getGaugeReserved",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "ResetComboBuff",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "PushComboBuff",
      "params": [
        {
          "name": "_HitID",
          "type": "System.UInt16"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "CheckComboBuff",
      "params": [
        {
          "name": "_HitID",
          "type": "System.UInt16"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "add_list",
      "params": [
        {
          "name": "_List",
          "type": "System.Collections.Generic.List`1<nBattle.cPlayer>"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "op_True",
      "params": [
        {
          "name": "s",
          "type": "nBattle.cPlayer"
        }
      ],
      "returns": "System.Boolean",
      "static": true
    },
    {
      "name": "op_False",
      "params": [
        {
          "name": "s",
          "type": "nBattle.cPlayer"
        }
      ],
      "returns": "System.Boolean",
      "static": true
    },
    {
      "name": "op_LogicalNot",
      "params": [
        {
          "name": "s",
          "type": "nBattle.cPlayer"
        }
      ],
      "returns": "System.Boolean",
      "static": true
    },
    {
      "name": "pl_die",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_ers",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "move_pl_suu",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "team_fusion",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "get_parallel",
      "params": [],
      "returns": "System.UInt32",
      "static": false
    },
    {
      "name": "get_multi_bits",
      "params": [
        {
          "name": "input",
          "type": "System.UInt32"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "WORLD_REQ",
      "params": [
        {
          "name": "_kind",
          "type": "System.SByte"
        },
        {
          "name": "_time",
          "type": "System.Int16"
        },
        {
          "name": "_bit",
          "type": "System.Byte"
        },
        {
          "name": "_opt",
          "type": "System.Byte"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "WORLD_REQ",
      "params": [
        {
          "name": "_req",
          "type": "nBattle.World.Req"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "DOWN_KAIHI_INIT",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "DOWN_KAIHI_DISABLE",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "DOWN_KAIHI_SUCCESS",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "NORMAL_NUKI",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "PUSH_NUKI",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "DMG_END_NUKI",
      "params": [
        {
          "name": "delay",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "getSuperGauge",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "setSuperGauge",
      "params": [
        {
          "name": "val",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "getSuperGaugeMax",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "setSuperGaugeMax",
      "params": [
        {
          "name": "val",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "isDead",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isGimmick",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "Unmovable",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "IgnorePush",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "IgnoreCorner",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isNonPlayer",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isObstacle",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "NotOperated",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "VanishDouble",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "push_position",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "calc_start_pos",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "isGuardDamage",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isGuardHit",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isGuardStun",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isNormal",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isDamage",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isDamageAll",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isDamageMove",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isCatchMove",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isHoldMove",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isHoldFix",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isHoldAll",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isHoldNow",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isHoldDamage",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isHoldPursuit",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isHoldHosei",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isAerialDamage",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isAttackResist",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isPoison",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isPoisonBurst",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isBomb",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isBombBurst",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isBombNow",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isDmgArmor",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isArmorBreak",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "_tst_cmn1",
      "params": [
        {
          "name": "flag",
          "type": "nBattle.PL_CMN1.FLAG"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "_set_cmn1",
      "params": [
        {
          "name": "flag",
          "type": "nBattle.PL_CMN1.FLAG"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "_clr_cmn1",
      "params": [
        {
          "name": "flag",
          "type": "nBattle.PL_CMN1.FLAG"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "isBACK",
      "params": [
        {
          "name": "input",
          "type": "System.UInt32"
        }
      ],
      "returns": "System.UInt32",
      "static": true
    },
    {
      "name": "get_scr_pos_x",
      "params": [],
      "returns": "via.sfix",
      "static": false
    },
    {
      "name": "GetVariation",
      "params": [],
      "returns": "System.Byte",
      "static": false
    },
    {
      "name": "GetBoundHeight",
      "params": [],
      "returns": "System.Byte",
      "static": false
    },
    {
      "name": "GetStunValue",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "GetStunMax",
      "params": [],
      "returns": "System.Int32",
      "static": true
    },
    {
      "name": "BackWallBit",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "BackStageWallBit",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "DisableState",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "get_IsMain",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "get_IsSub1",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "get_IsSub2",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "get_IsNobody",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "get_IsStand",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "get_IsCrouch",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "get_IsAir",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "get_IsDown",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "get_IsDamageBack",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "get_combo_hosei",
      "params": [],
      "returns": "System.SByte",
      "static": false
    },
    {
      "name": "IsJustParry",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "HitIndex",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "HitOffset",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "HitIndexMulti",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "CounterOffset",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "ArmIndex",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "GrdIndex",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "GrdIndexEx",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "DrvIndex",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "DrvIndexEx",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "get_blk_cmd_gu",
      "params": [],
      "returns": "nBattle.BLOCKING",
      "static": false
    },
    {
      "name": "set_blk_cmd_gu",
      "params": [
        {
          "name": "value",
          "type": "nBattle.BLOCKING"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_blk_cmd_gd",
      "params": [],
      "returns": "nBattle.BLOCKING",
      "static": false
    },
    {
      "name": "set_blk_cmd_gd",
      "params": [
        {
          "name": "value",
          "type": "nBattle.BLOCKING"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_blk_cmd_air",
      "params": [],
      "returns": "nBattle.BLOCKING",
      "static": false
    },
    {
      "name": "set_blk_cmd_air",
      "params": [
        {
          "name": "value",
          "type": "nBattle.BLOCKING"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_blk_cmd_vsa",
      "params": [],
      "returns": "nBattle.BLOCKING",
      "static": false
    },
    {
      "name": "set_blk_cmd_vsa",
      "params": [
        {
          "name": "value",
          "type": "nBattle.BLOCKING"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_r3_land",
      "params": [],
      "returns": "System.Byte",
      "static": false
    },
    {
      "name": "set_r3_land",
      "params": [
        {
          "name": "value",
          "type": "System.Byte"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_rDmgHitDT",
      "params": [],
      "returns": "nBattle.HIT_DT",
      "static": false
    },
    {
      "name": "get_rDmgHitDTs",
      "params": [],
      "returns": "nBattle.HIT_DT_TBL",
      "static": false
    },
    {
      "name": "DeepCopy",
      "params": [
        {
          "name": "From",
          "type": "nBattle.cPlayer"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_stand_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_stand_ck0",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_ck_stand",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_set_stand",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_sit_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_sit_ck0",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_ck_sit",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_set_sit",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_turn_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_ck_turn",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_set_turn",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_jump_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_ck_jump",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "com_jump_ok_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_set_jump",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_wjump_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_ck_wjump",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "com_wjump_ok_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_set_wjump",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_tjump_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_ck_tjump",
      "params": [],
      "returns": "System.UInt32",
      "static": false
    },
    {
      "name": "pl_act_set_tjump",
      "params": [
        {
          "name": "wall_flag",
          "type": "System.UInt32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_walk_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_ck_walk",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_set_walk",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_walk_ck0",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_ck_walk_rev",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_set_walk_rev",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_dwalk_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_ck_dwalk",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_set_dwalk",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_dwalk_ck0",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_set_dwalk_rev",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_act_ck_walk_end",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "ck_walk_end",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_ck_dwalk_end",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_fall_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_ck_fall",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_win_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_ck_win",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_set_win",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_death_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_ck_death",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_set_death",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_advancing_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_ck_advgrd",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_act_set_advgrd",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_touch_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_dm_touch_ck",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_tutorial_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "act_flying",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "fly_end_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "update_fly",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "fly_char_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "fly_e_char_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "fly_atk_ceil_adj",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "fly_ceil_adj",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "fly_floor_adj",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "fly_rate_move",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_dummy",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_footwork",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_walk",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_duck_walk",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_jump_wait",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_jump",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_jimen_sub",
      "params": [
        {
          "name": "isJumpGuard",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "act_land",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_jret",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_sit_down",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_sit",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_stand_up",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_std_turn",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_sit_turn",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_dash",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_sjump_wait",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_sjump",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_taoren",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_fall",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_getup",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_parry",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "parry_start",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "parry_loop",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "parry_hit",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "set_parry_end",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_def",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "def_start",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "def_loop",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "update_grd_base",
      "params": [
        {
          "name": "oldAct",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "def_hit",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "def_pdef",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "def_shaky",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_jdef",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "jdef_st",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "jdef_def",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_atck",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_sp_atck",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_win",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_sleep",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_tjump",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_kdash",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_ukemi",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_withdraw",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_st_set",
      "params": [
        {
          "name": "act",
          "type": "nBattle.ACT_ST.ID"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_act_set",
      "params": [
        {
          "name": "act",
          "type": "nBattle.ACT_ST.ID"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "act_set_dummy",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_work",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_walk",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_duck_walk",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_jump_wait",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_jump",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_jump_land",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_jump_ret",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_sitd",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_sit",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_stand",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_stand_turn",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_sit_turn",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_dash",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_flying",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_wjump",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_tjump",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_kdash",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_noki",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_sjump_wait",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_sjump",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_sjump_dmg",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_sjump_ret",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_fall",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_getup",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_def",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_jdef",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_atck",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_sp",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_win",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "isEnableToPlayTimeOverVoice",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "act_set_sleep",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_ukemi",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_touch",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_set_withdraw",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "moveAction",
      "params": [
        {
          "name": "Attribute",
          "type": "nBattle.CheckParam"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "updateSwitchKey",
      "params": [
        {
          "name": "_this",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": true
    },
    {
      "name": "updateLockKey",
      "params": [
        {
          "name": "_this",
          "type": "nBattle.cWork"
        },
        {
          "name": "Param",
          "type": "nAction.FLockKeyParam"
        }
      ],
      "returns": "System.Void",
      "static": true
    },
    {
      "name": "setParam",
      "params": [
        {
          "name": "Attribute",
          "type": "nBattle.CheckParam"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "setParamAfter",
      "params": [
        {
          "name": "Attribute",
          "type": "nBattle.CheckParam"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "act_touch",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_pose",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_pose_init",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_pose_move",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_pose_end",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_noki",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_noki_init",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_noki_fall",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_noki_jump_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_noki_jump",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_as",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_as_init",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_as_move",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_suki",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_v_suki",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_v_touch_in",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_fusion_in",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_damage_in",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_minion_in",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "update_resist",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "update_sp_armor",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "sp_armor_set",
      "params": [
        {
          "name": "Timer",
          "type": "System.Int16"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "sp_armor_start",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dam_taisei_move",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dam_taisei_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "dam_taisei_calc",
      "params": [
        {
          "name": "point",
          "type": "System.UInt32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dam_taisei_break",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dam_taisei_reset",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dam_taisei_start",
      "params": [
        {
          "name": "_add_stop",
          "type": "System.SByte"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_taisei_def_set",
      "params": [
        {
          "name": "Clear",
          "type": "System.SByte"
        },
        {
          "name": "Point",
          "type": "System.Byte"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dam_taisei_reset_on_damage",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_catch",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_hold",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_hold_dm",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "hold_dmXX",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "hold_dm06",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "hold_dm15",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "set_unlock",
      "params": [
        {
          "name": "pCatch",
          "type": "nBattle.cWork"
        },
        {
          "name": "HitNo",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "hold_damage",
      "params": [
        {
          "name": "pCatch",
          "type": "nBattle.cWork"
        },
        {
          "name": "_HitNo",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "GetCatchHitPos",
      "params": [
        {
          "name": "pAtk",
          "type": "nBattle.cWork"
        },
        {
          "name": "pDmg",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "CharacterAsset.HitRect16Base",
      "static": true
    },
    {
      "name": "GetOtherHitPos",
      "params": [
        {
          "name": "pAtk",
          "type": "nBattle.cWork"
        },
        {
          "name": "pDmg",
          "type": "nBattle.cWork"
        },
        {
          "name": "AtkInfo",
          "type": "nAction.AtckInfo"
        }
      ],
      "returns": "CharacterAsset.HitRect16Base",
      "static": true
    },
    {
      "name": "unlock_insurance",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "unlock_main",
      "params": [
        {
          "name": "pCatchP",
          "type": "nBattle.cPlayer"
        },
        {
          "name": "pCatch",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "unlock_common",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "is_shl_catch_now",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_catch_set",
      "params": [
        {
          "name": "pDmg",
          "type": "nBattle.cPlayer"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "shl_catch_set",
      "params": [
        {
          "name": "pAtk",
          "type": "nBattle.cWork"
        },
        {
          "name": "pDmg",
          "type": "nBattle.cPlayer"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_catch_out",
      "params": [
        {
          "name": "pAtk",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "throw_tech_init",
      "params": [
        {
          "name": "escape_no",
          "type": "System.SByte"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "throw_tech_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "throw_tech_ok",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "throw_tech_NG",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "setupCommandInfo",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "updateCommandInfo",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "updateDefaultTriggerGroup",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "updateTriggerGroup",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "updateApprovedCommand",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "updateApprovedCommandReady",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "updateExpectedCommand",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "resetApprovedHitstop",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "resetApprovedDefer",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "resetApprovedCommand",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "invalidateCommand",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "registApprovedInput",
      "params": [
        {
          "name": "pList",
          "type": "System.Collections.Generic.List`1<System.Int32>"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "cleanupApprovedInput",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "cleanupApprovedCommandGC",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "checkApprovedCommandCondition",
      "params": [
        {
          "name": "CheckTrigger",
          "type": "BCM.TRIGGER_FLAG"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "updateCommandTerminator",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "setCommandTerminatorSelf",
      "params": [
        {
          "name": "trgNo",
          "type": "System.Int32"
        },
        {
          "name": "pTrg",
          "type": "BCM.TRIGGER"
        },
        {
          "name": "isEasy",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "resetChargeGroup",
      "params": [
        {
          "name": "rBit",
          "type": "BCM.CHARGE_GROUP"
        },
        {
          "name": "isEasy",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "setCommandTerminator",
      "params": [
        {
          "name": "grpNo",
          "type": "System.Int32"
        },
        {
          "name": "isEasy",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "setCommandTerminatorMulti",
      "params": [
        {
          "name": "ClearTrigger",
          "type": "BCM.TRIGGER_FLAG"
        },
        {
          "name": "isNotChargeReset",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "resetCommandTerminator",
      "params": [
        {
          "name": "isCommandOnly",
          "type": "System.Boolean"
        },
        {
          "name": "isShotJust",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "checkCommandSpecial",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "checkCommandOther",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "checkCommandNormal",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "checkCommandGeneral",
      "params": [
        {
          "name": "CheckTrigger",
          "type": "BCM.TRIGGER_FLAG"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "checkCommandCondition",
      "params": [
        {
          "name": "trgNo",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "transition",
      "params": [
        {
          "name": "trgNo",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "setupAssistComboInfo",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "GetTrigger",
      "params": [
        {
          "name": "tId",
          "type": "System.Int32"
        }
      ],
      "returns": "BCM.TRIGGER",
      "static": false
    },
    {
      "name": "cmd_update_assist_combo",
      "params": [
        {
          "name": "isWorld",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "CheckCondition",
      "params": [
        {
          "name": "data",
          "type": "CharacterAsset.AssistComboRecipeData.ComboData"
        },
        {
          "name": "work",
          "type": "nBattle.AssistComboWork"
        },
        {
          "name": "step",
          "type": "System.Int32"
        },
        {
          "name": "isFistConditionForceSet",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "CheckAssistComboCondition",
      "params": [
        {
          "name": "data",
          "type": "CharacterAsset.AssistComboRecipeData.ComboData"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "status_update_assist_combo",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "is_time_stop",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "triggered_update_assist_combo",
      "params": [
        {
          "name": "trgId",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "cmd_end_check_assist_combo",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "ResetAssistComboParam",
      "params": [
        {
          "name": "work",
          "type": "nBattle.AssistComboWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "IsCountDelay",
      "params": [
        {
          "name": "nextData",
          "type": "CharacterAsset.AssistComboRecipeData.ComboData"
        },
        {
          "name": "work",
          "type": "nBattle.AssistComboWork"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "commandCheck",
      "params": [
        {
          "name": "isWorld",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Boolean[,]",
      "static": false
    },
    {
      "name": "IsGroundTriggerGroup",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "setAssistComboCommandTerminatorSelf",
      "params": [
        {
          "name": "work",
          "type": "nBattle.AssistComboWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "isChackCommandTriggerable",
      "params": [
        {
          "name": "recipe",
          "type": "BCM.ASSIST_COMBO_RECIPE"
        },
        {
          "name": "work",
          "type": "nBattle.AssistComboWork"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isChackPrecedeCommand",
      "params": [
        {
          "name": "recipe",
          "type": "BCM.ASSIST_COMBO_RECIPE"
        },
        {
          "name": "work",
          "type": "nBattle.AssistComboWork"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "is_master_assist",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "assist_set_master",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "calcMasterAssistTime",
      "params": [
        {
          "name": "gauge",
          "type": "System.Single"
        },
        {
          "name": "k",
          "type": "System.Single"
        }
      ],
      "returns": "System.Int16",
      "static": false
    },
    {
      "name": "master_assist_end_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "master_assist_end_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_com_ck",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_com_ck0",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_com_ckX",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "com_dash_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "com_dash_ok_ck",
      "params": [
        {
          "name": "isDrive",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "com_kdash_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "com_kdash_ok_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "com_sjump_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "com_jump_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "com_wjump_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_atck_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "atck_nm_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "atck_pa_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "atck_sp_ck",
      "params": [
        {
          "name": "isTrigger",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "ck_air_height",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "com_minion_ok_ck",
      "params": [],
      "returns": "nBattle.PARTNER_ID",
      "static": false
    },
    {
      "name": "com_minion_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "com_assist_ok_ck",
      "params": [
        {
          "name": "partnerNo",
          "type": "nBattle.PARTNER_ID"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_touch_ok_ck",
      "params": [],
      "returns": "nBattle.PARTNER_ID",
      "static": false
    },
    {
      "name": "getPartner",
      "params": [
        {
          "name": "partnerNo",
          "type": "nBattle.PARTNER_ID"
        },
        {
          "name": "isTouch",
          "type": "System.Boolean"
        }
      ],
      "returns": "nBattle.PARTNER_ID",
      "static": false
    },
    {
      "name": "checkTouchPlayer",
      "params": [
        {
          "name": "_isTouch",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "resetTriggerNotice",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "updateTriggerNotice",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "setTriggerNotice",
      "params": [
        {
          "name": "pGrp",
          "type": "BCM.TRIGGER_GROUP"
        },
        {
          "name": "trgGrp",
          "type": "nAction.FTriggerEnable"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "cmd_update_walk",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "cmd_update_crouch",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "cmd_update_jump",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "cmd_ck_njump_World",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "cmd_ck_wjump_World",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "cmd_update_guard",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "cmd_update_advgrd",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "cmd_update_avoid",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "cmd_update_touch",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "cmd_update_parry",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_com_parry_reset",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "cmd_update_blocking",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "blocking_ck",
      "params": [
        {
          "name": "index",
          "type": "nBattle.BLOCKING.ID"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_range_ck",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_range_ck_body",
      "params": [
        {
          "name": "Width",
          "type": "via.sfix"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_range_ck_imm",
      "params": [],
      "returns": "via.sfix",
      "static": false
    },
    {
      "name": "scr_hosei_L",
      "params": [
        {
          "name": "dontMove",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "scr_hosei_R",
      "params": [
        {
          "name": "dontMove",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_dead_push",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "wall_flag_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "wall_flag_ex",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "stage_range_ck",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "ignore_ruthless",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "ruthless_wall_L",
      "params": [
        {
          "name": "dontMove",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "ruthless_wall_R",
      "params": [
        {
          "name": "dontMove",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "ruthless_wall_U",
      "params": [
        {
          "name": "dontMove",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "obstacle_L",
      "params": [
        {
          "name": "dontMove",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "obstacle_R",
      "params": [
        {
          "name": "dontMove",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "getBodySideL",
      "params": [],
      "returns": "System.Single",
      "static": false
    },
    {
      "name": "getBodySideR",
      "params": [],
      "returns": "System.Single",
      "static": false
    },
    {
      "name": "update_hit_kind",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "combo_calc",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "combo_calc_fake",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "combo_calc_gd",
      "params": [
        {
          "name": "_gard_combo_cnt",
          "type": "System.Byte"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "combo_calc_gdex",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "combo_dmg_init",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "combo_dmg_reset",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "combo_grd_reset",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "combo_pry_reset",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "is_dmg_combo",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "combo_reset",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "combo_nage",
      "params": [
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "combo_min_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "combo_add_sub",
      "params": [
        {
          "name": "pDmg",
          "type": "nBattle.cPlayer"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "combo_calc_air",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "combo_air_reset",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "combo_air_start",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "combo_scale_update",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "update_expected_dir",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "update_result_dir",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_rl_set",
      "params": [
        {
          "name": "isOnlyRL",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_rl_set_turn",
      "params": [
        {
          "name": "isOnlyRL",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_rl_set_sjump",
      "params": [
        {
          "name": "isOnlyRL",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_rl_set_hold",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_rl_dir",
      "params": [
        {
          "name": "_tar_pos",
          "type": "via.sfix"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "get_turn_dir",
      "params": [
        {
          "name": "_tar_pos",
          "type": "via.sfix"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "set_damage_chr_dir",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        },
        {
          "name": "isInnerOnly",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "set_damage_chr_dir_fr",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        },
        {
          "name": "cond_to_front",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_damage",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_guard",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_parry",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_zuri",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_release",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_break",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_buttobi",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dmb_init",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dmb_move",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dmb_bound",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dmb_bound_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "set_bound_action",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_butt_slide",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dmbs_init",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dmbs_move",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_ashi",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "goro_to_kuzure",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "shaky_to_kuzure",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_kuzure",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_slide",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "butt_to_slide",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_butt_oki",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_ned",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "butt_to_down",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "butt_to_sleep",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_down",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "down_muteki",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_sleep",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "lie_down_main",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "wall_to_piyo",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_piyo_loop",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "stick_to_wall",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_wall_crash",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "wall_piyo_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_wall_piyo",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "butt_to_goro",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_goro",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "goro_to_down",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_zuri_move",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_adv_zuri",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "taisei_zuri_move",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "draw_zuri_move",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_buttobi_move",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "buttobi_grav_ck",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_butt_hit_nuki",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_butt_floor",
      "params": [
        {
          "name": "level",
          "type": "System.Int32"
        },
        {
          "name": "absolute",
          "type": "System.Int32"
        },
        {
          "name": "noShake",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "set_tataki_sound",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "set_throw_sound",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "set_floor_flag",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "wall_bound_ck",
      "params": [
        {
          "name": "ck_wall_bit",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "wall_bound_set",
      "params": [
        {
          "name": "isSecond",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "wall_bound_sub",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "floor_bound_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "avoid_check",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "avoid_set",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "down_ukemi_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "jump_ukemi_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "nage_ukemi_set",
      "params": [
        {
          "name": "Type",
          "type": "nBattle.UKEMI_TYPE"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "sandbag_end_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "sandbag_end_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "butt_taoren_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "butt_taoren_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_blocking_dmg",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_blocking_atk",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_parry_dmg",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "justParry",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_guard_set",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_def_set",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "low_guard_ck",
      "params": [
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "guard_pow_ofs",
      "params": [
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "set_guard_dm_info",
      "params": [
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        },
        {
          "name": "isCrouch",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "set_d_guard_dm_info",
      "params": [
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        },
        {
          "name": "isCrouch",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_guard_kind",
      "params": [
        {
          "name": "_DmgPart",
          "type": "System.Byte"
        },
        {
          "name": "isCrouch",
          "type": "System.Boolean"
        }
      ],
      "returns": "nBattle.ACT_ID",
      "static": false
    },
    {
      "name": "get_d_guard_kind",
      "params": [
        {
          "name": "_DmgPart",
          "type": "System.Byte"
        },
        {
          "name": "isCrouch",
          "type": "System.Boolean"
        }
      ],
      "returns": "nBattle.ACT_ID",
      "static": false
    },
    {
      "name": "get_parry_kind",
      "params": [
        {
          "name": "_DmgPart",
          "type": "System.Byte"
        }
      ],
      "returns": "nBattle.ACT_ID",
      "static": false
    },
    {
      "name": "pl_damage_set",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "throw_dm_sub0",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "throw_dm_sub1",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "throw_dm_sub2",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "throw_dm_sub3",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_forecast_vital",
      "params": [
        {
          "name": "pHold",
          "type": "nBattle.cPlayer"
        }
      ],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "pl_dm_sub",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "piyori_buttobi_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "dm_set_guard",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_break",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_zuri",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_buttobi_comn",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_buttobi_o",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_buttobi_n",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_buttobi_go",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_nage_buttobi",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_nage_release",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_buttobi_t",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_buttobi_tn",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_butt_t_comn",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_ashi",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_buttobi_b",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_kuzure",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_kuzure_comn",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_kezu_death",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_slide",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_buttobi_k",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_buttobi_kn",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_buttobi_s",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_buttobi_pi",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "muteki_butt_comn",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "set_piyo_all",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_piyo_loop",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_ned",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_down",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_set_sleep",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "setDownChara",
      "params": [
        {
          "name": "isLie",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "setZuriDmgChara",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "setDamageChara",
      "params": [
        {
          "name": "_tbl",
          "type": "nBattle.ACT_ID[]"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "setAirDmgChara",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "setDirectionStartChara",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "setDirectionChara",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "zuri_action_scale",
      "params": [
        {
          "name": "_damage_time",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "zuri_rate_set",
      "params": [
        {
          "name": "isGuard",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "zuri_rate_reverse",
      "params": [
        {
          "name": "mov_pos",
          "type": "via.sfix"
        },
        {
          "name": "is_transfer",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "taisei_rate_reverse",
      "params": [
        {
          "name": "mov_pos",
          "type": "via.sfix"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "zuri_rate_transfer",
      "params": [
        {
          "name": "rVsZuri",
          "type": "nBattle.VS_ZURI"
        },
        {
          "name": "rZuri",
          "type": "nBattle.ZURI"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "zuri_rate_sub",
      "params": [
        {
          "name": "calc_vec",
          "type": "nBattle.ZURI"
        },
        {
          "name": "isLeft",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "suikomi_ck_zuri",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "suikomi_ck_butt",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "vec_rate_set",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "calc_damage_speed",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "calc_damage_speed_x",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "calc_damage_vec",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "aerial_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "buttobi_dm_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "taisei_zuri_set",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "_Rate",
          "type": "System.Int16"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "overwritten_on_death",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "kuzure_die_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "die_buttobi_set",
      "params": [
        {
          "name": "fromHitCheck",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "poison_death",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "death_sub",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "finish_kind_sub",
      "params": [
        {
          "name": "AkebonoPos",
          "type": "via.vec3"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "death_down",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "update_down_to_stand",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "do_down_to_stand",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_data_set",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "DamageDir",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_data_set_ex",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "set_dm_etc",
      "params": [
        {
          "name": "pAtk",
          "type": "nBattle.cPlayer"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "set_dm_attr",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        },
        {
          "name": "onlyLooks",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "set_dm_attr_direct",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "DmgKind",
          "type": "nBattle.nHit.DAMAGE_KIND"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_kind_update",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "DmgKind",
          "type": "nBattle.nHit.DAMAGE_KIND"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_kind_before",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "dm_kind_after",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "set_dm_piyo",
      "params": [
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "hit_st_guard",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "GuardAttribute",
      "params": [
        {
          "name": "Type",
          "type": "nBattle.nHit.HIT_ATCK_KIND"
        }
      ],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "IsGroundDamage",
      "params": [
        {
          "name": "_type",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Boolean",
      "static": true
    },
    {
      "name": "IsDownDamage",
      "params": [
        {
          "name": "_type",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Boolean",
      "static": true
    },
    {
      "name": "GetDamageType",
      "params": [
        {
          "name": "_cate",
          "type": "System.Int32"
        }
      ],
      "returns": "CharacterAsset.DamageType",
      "static": true
    },
    {
      "name": "pincer_attack_check",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "count_up_down",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "setDamageData",
      "params": [
        {
          "name": "tbl",
          "type": "nBattle.HIT_DT_TBL"
        },
        {
          "name": "hit_dt",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "setDamageDataCmn",
      "params": [
        {
          "name": "hitNo",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "overwriteDamageData",
      "params": [
        {
          "name": "hit_dt",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "setDamageInfo",
      "params": [
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "release_powerup",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "saveAttackPlayer",
      "params": [
        {
          "name": "pAtk",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "saveZuriPlayer",
      "params": [
        {
          "name": "pAtk",
          "type": "nBattle.cWork"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "isDownAction",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "setConscious",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "setBoundHeight",
      "params": [
        {
          "name": "_Height",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "getGuardTime",
      "params": [],
      "returns": "System.Byte",
      "static": false
    },
    {
      "name": "grd_stop_set",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "reset_calc_param",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "reset_dm_param_always",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "reset_dm_param_hit",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "reset_dm_flags",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "init_dm_routine",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "update_auto_guard_time",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "update_force_no_gd_time",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "change_abnormal_status",
      "params": [
        {
          "name": "pAtk",
          "type": "nBattle.cWork"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        },
        {
          "name": "hitNo",
          "type": "System.Int32"
        },
        {
          "name": "ckFlag",
          "type": "nBattle.DMG_CONDITION.ATTR"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "set_counter_flag",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "set_counter_msg",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "super_add",
      "params": [
        {
          "name": "Add",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "super_add_abs",
      "params": [
        {
          "name": "Add",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "hit_gauge_calc",
      "params": [
        {
          "name": "pAtk",
          "type": "nBattle.cPlayer"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        },
        {
          "name": "pAtmDT",
          "type": "CharacterAsset.AtemiData"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "parry_gauge_calc_super_dm",
      "params": [
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "parry_gauge_calc_super_at",
      "params": [
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "parry_gauge_calc_focus_dm",
      "params": [
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        },
        {
          "name": "isJust",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "parry_gauge_calc_focus_at",
      "params": [
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "super_buff_exec",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "super_buff_reset",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "super_buff_set",
      "params": [
        {
          "name": "Add",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "super_buff_exist",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "focus_buff_exec",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "focus_buff_reset",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "focus_buff_set",
      "params": [
        {
          "name": "Add",
          "type": "System.Int32"
        },
        {
          "name": "Kind",
          "type": "System.Int32"
        },
        {
          "name": "Type",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "focus_buff_exist",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "focus_gauge_use",
      "params": [
        {
          "name": "Add",
          "type": "System.Int32"
        },
        {
          "name": "Kind",
          "type": "System.Int32"
        },
        {
          "name": "Type",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "focus_gauge_hit",
      "params": [
        {
          "name": "Add",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "focus_full_recover",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "focus_gauge_add",
      "params": [
        {
          "name": "Add",
          "type": "System.Int32"
        },
        {
          "name": "Type",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "focus_wait_set",
      "params": [
        {
          "name": "newWait",
          "type": "System.Int32"
        },
        {
          "name": "isOverwrite",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "focus_clamp",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "vital_add",
      "params": [
        {
          "name": "addVital",
          "type": "System.Int16"
        },
        {
          "name": "addHeal",
          "type": "System.Int16"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "vital_add_heal",
      "params": [
        {
          "name": "addVital",
          "type": "System.Int16"
        },
        {
          "name": "addHeal",
          "type": "System.Int16"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "vital_add_new",
      "params": [
        {
          "name": "addVital",
          "type": "System.Int16"
        },
        {
          "name": "addHeal",
          "type": "System.Int16"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "vital_sub",
      "params": [
        {
          "name": "addVital",
          "type": "System.Int16"
        },
        {
          "name": "addHeal",
          "type": "System.Int16"
        },
        {
          "name": "isDie",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "vital_add_main",
      "params": [
        {
          "name": "addVital",
          "type": "System.Int16"
        },
        {
          "name": "addHeal",
          "type": "System.Int16"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "hit_dm_calc",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        },
        {
          "name": "extRate",
          "type": "System.Int32"
        },
        {
          "name": "pAtmDT",
          "type": "CharacterAsset.AtemiData"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "hit_dm_calc_fake",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        },
        {
          "name": "extRate",
          "type": "System.Int32"
        },
        {
          "name": "pAtmDT",
          "type": "CharacterAsset.AtemiData"
        }
      ],
      "returns": "System.ValueTuple`3<System.Int32,System.Int32,System.Int32>",
      "static": false
    },
    {
      "name": "getGMV",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "dmBase",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Int64",
      "static": false
    },
    {
      "name": "grd_dm_calc",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "pMst",
          "type": "nBattle.cPlayer"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pry_dm_calc",
      "params": [
        {
          "name": "pAtk",
          "type": "nBattle.cPlayer"
        },
        {
          "name": "pHitDT_sp",
          "type": "nBattle.HIT_DT"
        },
        {
          "name": "pHitDT_dr",
          "type": "nBattle.HIT_DT"
        },
        {
          "name": "isJust",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "vital_adjust",
      "params": [
        {
          "name": "pAtk",
          "type": "nBattle.cPlayer"
        },
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "via.sfix",
      "static": false
    },
    {
      "name": "damage_cap",
      "params": [
        {
          "name": "pAtk",
          "type": "nBattle.cPlayer"
        }
      ],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "vital_calc",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "pMst",
          "type": "nBattle.cPlayer"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        },
        {
          "name": "redVal",
          "type": "System.Int32"
        },
        {
          "name": "whiteVal",
          "type": "System.Int32"
        },
        {
          "name": "isGuard",
          "type": "System.Boolean"
        },
        {
          "name": "pinkVal",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "no_death_ck",
      "params": [
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        },
        {
          "name": "isGuard",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "no_death_ck_raw",
      "params": [
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        },
        {
          "name": "isGuard",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "dying_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "vital_convert",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "pMst",
          "type": "nBattle.cPlayer"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        },
        {
          "name": "damageVal",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "CanBlocking",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "CanParry",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "CanDGuard",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "CanGuard",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "CanAtemi",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "CanArmor",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "set_guard_attr",
      "params": [
        {
          "name": "HitKind",
          "type": "nBattle.nHit.HIT_ATCK_KIND"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "set_guard_st",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "self_guard_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "auto_guard_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "auto_blocking_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "hit_guard_ck",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "hitKind",
          "type": "nBattle.nHit.HIT_ATCK_KIND"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "hit_blocking_ck",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "hitKind",
          "type": "nBattle.nHit.HIT_ATCK_KIND"
        }
      ],
      "returns": "nBattle.nHit.DMG_ATTR",
      "static": false
    },
    {
      "name": "hit_d_guard_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "hit_parry_ck",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "hitKind",
          "type": "nBattle.nHit.HIT_ATCK_KIND"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "hit_just_ck",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        },
        {
          "name": "hitKind",
          "type": "nBattle.nHit.HIT_ATCK_KIND"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "hit_mekuri_ck",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "stage_init",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "round_init",
      "params": [
        {
          "name": "SkipParamSet",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "late_join",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_init_sub",
      "params": [
        {
          "name": "deepInit",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_touch_init",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "init_pos_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "revive",
      "params": [
        {
          "name": "_Action",
          "type": "nBattle.ACT_ID"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_input_main",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_input_fake",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_input_attr",
      "params": [],
      "returns": "nBattle.INPUT_ATTR",
      "static": false
    },
    {
      "name": "pl_input_sub",
      "params": [
        {
          "name": "_Attr",
          "type": "nBattle.INPUT_ATTR"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "IsInputEasy",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "IsInputExtra",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_norm",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "notPiyori",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "resetPiyori",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "resetPiyoriAll",
      "params": [
        {
          "name": "isForced",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "isPiyoButt",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "startPiyoButt",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "isStandPiyo",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "startStandPiyo",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "resetPiyoPoint",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "isPiyoPointEmpty",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "isPiyoPointReady",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "calcPiyoPoint",
      "params": [
        {
          "name": "_sub",
          "type": "System.Byte"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "updatePiyoRecover",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "resetPiyoOnDamage",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_int",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "HitStopMain",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "HitStopMainSlow",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "MoveAfter",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "MoveCheckAfter",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "MoveCheckAfterSync",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "Move4_1",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "Move4_2",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "Move4_3",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "Move4_4",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_mov1",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_mov2",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_mov3",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_style_update",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_style_change",
      "params": [
        {
          "name": "next",
          "type": "System.Int32"
        },
        {
          "name": "ope",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_style_set",
      "params": [
        {
          "name": "newStyle",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_style_timer_set",
      "params": [
        {
          "name": "value",
          "type": "System.Int32"
        },
        {
          "name": "ope",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_style_end_ck",
      "params": [
        {
          "name": "act",
          "type": "System.UInt32"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_style_wait_ck",
      "params": [
        {
          "name": "act",
          "type": "System.UInt32"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_style_interrupt_time",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_style_interrupt_revoke",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_tjump_rate",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_sjump_adj",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_sjump_brake",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_sjump_down",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "jump_work_clr",
      "params": [
        {
          "name": "isFlyWorkSkip",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "WorldStart",
      "params": [
        {
          "name": "isContinue",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "WorldEnd",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "WorldForceEnd",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "hit_slow_move",
      "params": [
        {
          "name": "IsDamage",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "hit_stop_bibi",
      "params": [
        {
          "name": "_Value",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "nuke_mark_set",
      "params": [
        {
          "name": "Pos",
          "type": "via.Sfix3"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_nuke_pos",
      "params": [
        {
          "name": "pAtk",
          "type": "nBattle.cPlayer"
        },
        {
          "name": "pDmg",
          "type": "nBattle.cPlayer"
        }
      ],
      "returns": "via.Sfix3",
      "static": false
    },
    {
      "name": "land_smoke_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_kyori",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "get_drive_type",
      "params": [
        {
          "name": "pTrg",
          "type": "BCM.TRIGGER"
        }
      ],
      "returns": "System.ValueTuple`2<System.Int32,System.Int32>",
      "static": false
    },
    {
      "name": "checkAssist",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "jdef_grav_min",
      "params": [],
      "returns": "via.sfix",
      "static": false
    },
    {
      "name": "set_lock_end_pos",
      "params": [
        {
          "name": "isFlip",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "addShellNum",
      "params": [
        {
          "name": "pShl",
          "type": "nBattle.cWork"
        },
        {
          "name": "add",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "resetZuri",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "GetWinPose",
      "params": [],
      "returns": "nBattle.ACT_ID",
      "static": false
    },
    {
      "name": "GetWinPoseException",
      "params": [
        {
          "name": "_actNo",
          "type": "nBattle.ACT_ID"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "SetWinPose",
      "params": [
        {
          "name": "_actNo",
          "type": "nBattle.ACT_ID"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "SetDriveEmpty",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "SetDriveMax",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "IsFootwork",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "IsCrouchLoop",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "IsDownLoop",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_mv_ck",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "clear_param_common",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "clear_param_piyo",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "clear_param_ground",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "set_piyo_param",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "set_to_normal",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "set_to_normal0",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_jump_ret",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_jump_ret2",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_sjump_ret",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_jump_return",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "target_change_req",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_def_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "defense_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "get_guard_bit",
      "params": [],
      "returns": "System.Byte",
      "static": false
    },
    {
      "name": "jdef_limit_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "guard_lever_ck",
      "params": [
        {
          "name": "isHitCheck",
          "type": "System.Boolean"
        },
        {
          "name": "isBackDash",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "guard_lever_ck_pincer",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "guard_lever_ck_direct",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "guard_lever_sub",
      "params": [
        {
          "name": "pHit",
          "type": "nBattle.cWork"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "guard_style_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "blocking_style_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "blocking_style_ckA",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "blocking_style_ckG",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "vector_end_ck",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "sleep_cancel_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_jimen_ck",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_ground_hosei",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_land_status",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_land_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_land_sub",
      "params": [
        {
          "name": "_Pose",
          "type": "System.Int32"
        },
        {
          "name": "_Attr",
          "type": "nBattle.cPlayer.LAND_SET"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "assist_pos_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "minion_pos_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "jump_in_pos_set",
      "params": [
        {
          "name": "InTime",
          "type": "System.Int32"
        },
        {
          "name": "OfsX",
          "type": "System.Int32"
        },
        {
          "name": "isAir",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "set_default_z",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "reset_jump_param",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "jump_dir_set",
      "params": [
        {
          "name": "isCmdDir",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "rl_and_dir_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "jimen_hosei",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "can_grab",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "sp_speed_set",
      "params": [
        {
          "name": "Timer",
          "type": "System.Int16"
        },
        {
          "name": "Count",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "update_sp_speed",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "update_hit_muteki",
      "params": [
        {
          "name": "pAtk",
          "type": "nBattle.cWork"
        },
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "set_hit_muteki",
      "params": [
        {
          "name": "pAtk",
          "type": "nBattle.cWork"
        },
        {
          "name": "_MutekiTime",
          "type": "System.Byte"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "reserve_aerial_start",
      "params": [
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "decide_aerial_start",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "set_rolling_time",
      "params": [
        {
          "name": "pHitDT",
          "type": "nBattle.HIT_DT"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "init_jump_tbl",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "destroy_jump_tbl",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_common",
      "params": [],
      "returns": "nBattle.cPlayer",
      "static": false
    },
    {
      "name": "pl_entry_sub",
      "params": [
        {
          "name": "pMst",
          "type": "nBattle.cPlayer"
        },
        {
          "name": "dir",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "master_change_sub",
      "params": [],
      "returns": "nBattle.cPlayer",
      "static": false
    },
    {
      "name": "pl_touch_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_set_command",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_set_variable",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_set_damage",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_set_sort",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_sort_sub",
      "params": [
        {
          "name": "pTop",
          "type": "nBattle.cPlayer"
        },
        {
          "name": "pEnd",
          "type": "nBattle.cPlayer"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_set_jump",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "touch_jump_sub",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_assist_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "assist_set_coop",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "assist_set_minion",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_assist_dir",
      "params": [
        {
          "name": "asi",
          "type": "nBattle.cPlayer"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "pl_master_chg",
      "params": [
        {
          "name": "pMst",
          "type": "nBattle.cPlayer"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "gattai_end_ck1",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "gattai_end_set",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_unique_param_set",
      "params": [
        {
          "name": "value",
          "type": "System.SByte"
        },
        {
          "name": "ope",
          "type": "System.Int32"
        },
        {
          "name": "index",
          "type": "System.Int32"
        },
        {
          "name": "extIndex",
          "type": "System.Int32"
        },
        {
          "name": "limit",
          "type": "System.SByte"
        },
        {
          "name": "isAddNotify",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_unique_param_set",
      "params": [
        {
          "name": "actParam",
          "type": "app.esports.ActionParam"
        },
        {
          "name": "value",
          "type": "System.SByte"
        },
        {
          "name": "ope",
          "type": "System.Int32"
        },
        {
          "name": "index",
          "type": "System.Int32"
        },
        {
          "name": "extIndex",
          "type": "System.Int32"
        },
        {
          "name": "limit",
          "type": "System.SByte"
        },
        {
          "name": "isAddNotify",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_unique_param_set",
      "params": [
        {
          "name": "InParam",
          "type": "app.esports.B4"
        },
        {
          "name": "extIndex",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "pl_unique_param_copy",
      "params": [
        {
          "name": "pWork",
          "type": "nBattle.cWork"
        },
        {
          "name": "_Param",
          "type": "nAction.FEventParam"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": ".cctor",
      "params": [],
      "returns": "System.Void",
      "static": true
    },
    {
      "name": "<act_sleep>g___setTouch|512_0",
      "params": [
        {
          "name": "mstTime",
          "type": "System.Int32"
        },
        {
          "name": "parTime",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<updateSwitchKey>g___HitTarget|557_0",
      "params": [
        {
          "name": "",
          "type": "nBattle.cPlayer.<>c__DisplayClass557_0"
        }
      ],
      "returns": "nBattle.cPlayer",
      "static": true
    },
    {
      "name": "<setParam>g___GetTargetID|559_0",
      "params": [],
      "returns": "System.Int32",
      "static": false
    },
    {
      "name": "<touch_noki_jump>g___touch_noki_rinit|572_0",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<throw_tech_ck>g___DoEscape|618_0",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<throw_tech_ck>g___SetEscapeEnd|618_1",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<updateTriggerGroup>g___CheckInputType|624_0",
      "params": [
        {
          "name": "_mode",
          "type": "System.UInt32"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "<updateTriggerGroup>g___GetCheckFlag|624_1",
      "params": [
        {
          "name": "_hit_st",
          "type": "nBattle.nHit.HIT_ST"
        }
      ],
      "returns": "System.UInt32",
      "static": true
    },
    {
      "name": "<updateExpectedCommand>g___UpdateDynamic|633_0",
      "params": [
        {
          "name": "idx",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<setCommandTerminatorMulti>g___ResetSub|646_0",
      "params": [
        {
          "name": "trgNo",
          "type": "System.Int32"
        },
        {
          "name": "",
          "type": "nBattle.cPlayer.<>c__DisplayClass646_0"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<setupAssistComboInfo>g__GetActualTriggerIdx|654_0",
      "params": [
        {
          "name": "trg",
          "type": "BCM.TRIGGER"
        },
        {
          "name": "isNoCheckCommandNo",
          "type": "System.Boolean"
        }
      ],
      "returns": "BCM.TRIGGER_FLAG",
      "static": false
    },
    {
      "name": "<cmd_update_assist_combo>g__UpdateAssistCombo|657_0",
      "params": [
        {
          "name": "work",
          "type": "nBattle.AssistComboWork"
        },
        {
          "name": "isCount",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<cmd_update_assist_combo>g__TriggeredProc|657_1",
      "params": [
        {
          "name": "work",
          "type": "nBattle.AssistComboWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<cmd_update_assist_combo>g__CanReserve|657_2",
      "params": [
        {
          "name": "work",
          "type": "nBattle.AssistComboWork"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "<cmd_update_assist_combo>g__TriggerCheck|657_3",
      "params": [
        {
          "name": "work",
          "type": "nBattle.AssistComboWork"
        },
        {
          "name": "step",
          "type": "System.Int32"
        }
      ],
      "returns": "nBattle.cPlayer.TRG_COND",
      "static": false
    },
    {
      "name": "<cmd_update_assist_combo>g__TriggerAssistCombo|657_4",
      "params": [
        {
          "name": "work",
          "type": "nBattle.AssistComboWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<cmd_update_assist_combo>g__RestrictCheckCommand|657_5",
      "params": [
        {
          "name": "work",
          "type": "nBattle.AssistComboWork"
        },
        {
          "name": "ignore_restrict_trigger",
          "type": "BCM.TRIGGER_FLAG"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<cmd_update_assist_combo>g__AssistComboFirstStep|657_6",
      "params": [
        {
          "name": "work",
          "type": "nBattle.AssistComboWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<cmd_update_assist_combo>g__IsExistNextStep|657_7",
      "params": [
        {
          "name": "work",
          "type": "nBattle.AssistComboWork"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "<cmd_update_assist_combo>g__CheckChargeCondition|657_8",
      "params": [
        {
          "name": "work",
          "type": "nBattle.AssistComboWork"
        },
        {
          "name": "step",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "<cmd_update_assist_combo>g__CheckDelayCondition|657_9",
      "params": [
        {
          "name": "work",
          "type": "nBattle.AssistComboWork"
        },
        {
          "name": "delay",
          "type": "System.UInt32"
        }
      ],
      "returns": "System.Boolean",
      "static": true
    },
    {
      "name": "<cmd_update_assist_combo>g__updateAssistComboCommandTerminator|657_10",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<cmd_update_assist_combo>g__resetAssistCombo_World|657_11",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<status_update_assist_combo>g__UpdateToNormal|660_0",
      "params": [
        {
          "name": "work",
          "type": "nBattle.AssistComboWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<status_update_assist_combo>g__UpdateTransitionConditions|660_1",
      "params": [
        {
          "name": "work",
          "type": "nBattle.AssistComboWork"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<status_update_assist_combo>g__CheckEndCondition|660_2",
      "params": [
        {
          "name": "work",
          "type": "nBattle.AssistComboWork"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "<cmd_end_check_assist_combo>g__IsEndAssistCombo|663_0",
      "params": [
        {
          "name": "work",
          "type": "nBattle.AssistComboWork"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "<commandCheck>g__isCheck|666_0",
      "params": [
        {
          "name": "recipe_data",
          "type": "BCM.ASSIST_COMBO_RECIPE"
        },
        {
          "name": "in_work",
          "type": "nBattle.AssistComboWork"
        },
        {
          "name": "",
          "type": "nBattle.cPlayer.<>c__DisplayClass666_0"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "<commandCheck>g__checkCommandMain|666_1",
      "params": [
        {
          "name": "recipe_data",
          "type": "BCM.ASSIST_COMBO_RECIPE"
        },
        {
          "name": "in_work",
          "type": "nBattle.AssistComboWork"
        },
        {
          "name": "press",
          "type": "System.UInt32"
        },
        {
          "name": "direct",
          "type": "System.UInt32"
        },
        {
          "name": "",
          "type": "nBattle.cPlayer.<>c__DisplayClass666_0"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "<commandCheck>g__GetLever|666_2",
      "params": [
        {
          "name": "lever_raw",
          "type": "System.UInt32"
        },
        {
          "name": "",
          "type": "nBattle.cPlayer.<>c__DisplayClass666_0"
        }
      ],
      "returns": "System.UInt32",
      "static": false
    },
    {
      "name": "<pl_range_ck_body>g___HoseiSub|715_0",
      "params": [
        {
          "name": "pTgt",
          "type": "nBattle.cPlayer"
        },
        {
          "name": "",
          "type": "nBattle.cPlayer.<>c__DisplayClass715_0"
        },
        {
          "name": "",
          "type": "nBattle.cPlayer.<>c__DisplayClass715_1"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<pl_range_ck_body>g___HoseiNormal|715_1",
      "params": [
        {
          "name": "",
          "type": "nBattle.cPlayer.<>c__DisplayClass715_0"
        },
        {
          "name": "",
          "type": "nBattle.cPlayer.<>c__DisplayClass715_1"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<dm_release>g___UpdateDown|793_0",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<dm_release>g___EndSub|793_1",
      "params": [
        {
          "name": "isTrade",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<getGuardTime>g__isPinchGuard|959_0",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "<set_counter_msg>g___ThrowCheck|973_0",
      "params": [
        {
          "name": "",
          "type": "nBattle.cPlayer.<>c__DisplayClass973_0"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "<focus_clamp>g___canRecovery|994_0",
      "params": [],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "<set_guard_st>g___TrainingParrySet|1019_0",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<pl_int>g___waitUpdateAction|1056_0",
      "params": [],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<HitStopMain>g___updateAction|1057_0",
      "params": [
        {
          "name": "_Flag",
          "type": "System.UInt64"
        }
      ],
      "returns": "System.Void",
      "static": false
    },
    {
      "name": "<MoveAfter>g___zuri_move|1059_0",
      "params": [
        {
          "name": "Zuri",
          "type": "nBattle.ZURI"
        },
        {
          "name": "Ignore",
          "type": "System.Boolean"
        }
      ],
      "returns": "System.Boolean",
      "static": false
    },
    {
      "name": "<MoveAfter>g___wall_push|1059_1",
      "params": [
        {
          "name": "targetID",
          "type": "System.Int32"
        }
      ],
      "returns": "System.Void",
      "static": false
    }
  ],
  "parent": "nBattle.cWork",
  "size": 1128,
  "type": "nBattle.cPlayer",
  "valuetype": false
}

8:32:50 PM · array.get

{
  "from": 0,
  "length": 6,
  "values": [
    {
      "h": 59,
      "type": "nBattle.cPlayer"
    },
    {
      "h": 60,
      "type": "nBattle.cPlayer"
    },
    {
      "h": 61,
      "type": "nBattle.cPlayer"
    },
    {
      "h": 62,
      "type": "nBattle.cPlayer"
    },
    {
      "h": 63,
      "type": "nBattle.cPlayer"
    },
    {
      "h": 64,
      "type": "nBattle.cPlayer"
    }
  ]
}

8:32:43 PM · array.get

BridgeError: nBattle.sPlayer is not an array

8:32:17 PM · field.get

{
  "h": 58,
  "type": "nBattle.cPlayer[]"
}

8:30:51 PM · field.get

{
  "h": 57,
  "type": "app.TrainingInput"
}

8:30:43 PM · field.get

{
  "h": 56,
  "type": "app.BattleTeam"
}

8:30:38 PM · field.get

{
  "h": 55,
  "type": "nBattle.sPlayer"
}

8:30:16 PM · type.find

{
  "h": 54,
  "static": true,
  "type": "gBattle"
}

```
