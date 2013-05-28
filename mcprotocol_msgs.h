/*
Заголовочный файл, включающий в себя классы сообщений для удобства.
Названия классов взяты из вики по ссылке ниже, возможны переименования.
http://mc.kev009.com/Protocol

TODO

0x68 недоработано и не может быть полноценно использовано, доработать.
0x0D непригодно для использования на сервере, поправить.
0x67 недоработано, годится только для считывания и пропуска байт из потока.
0x38 аналогично
Возможно, некоторые сообщения не переработаны в новый стиль, найти и доделать.

*/

#ifndef _MCPROTOCOL_MSGS_H_
#define _MCPROTOCOL_MSGS_H_

#include "msg_0x00_keepalive_tw.h"
#include "msg_0x01_loginrequest_stc.h"
#include "msg_0x02_handshake_cts.h"
#include "msg_0x03_chatmessage_tw.h"
#include "msg_0x04_timeupdate_stc.h"
#include "msg_0x05_entityequipment_stc.h"
#include "msg_0x06_spawnposition_stc.h"
#include "msg_0x07_useentity_cts.h"
#include "msg_0x08_healthupdate_stc.h"
#include "msg_0x09_respawn_stc.h"
#include "msg_0x0a_player_cts.h"
#include "msg_0x0b_playerposition_cts.h"
#include "msg_0x0c_playerlook_cts.h"
#include "msg_0x0d_playerpositionandlook_tw.h"
#include "msg_0x0e_playerdigging_cts.h"
#include "msg_0x0f_playerblockplacement_cts.h"
#include "msg_0x10_helditemchange_tw.h"
#include "msg_0x11_usebed_stc.h"
#include "msg_0x12_animation_tw.h"
#include "msg_0x13_entityaction_cts.h"
#include "msg_0x14_spawnnamedentity_stc.h"
#include "msg_0x16_collectitem_stc.h"
#include "msg_0x17_spawnobject_stc.h"
#include "msg_0x18_spawnmob_stc.h"
#include "msg_0x19_spawnpainting_stc.h"
#include "msg_0x1a_spawnexperienceorb_stc.h"
#include "msg_0x1c_entityvelocity_stc.h"
#include "msg_0x1d_destroyentity_stc.h"
#include "msg_0x1e_entity_stc.h"
#include "msg_0x1f_entityrelativemove_stc.h"
#include "msg_0x20_entitylook_stc.h"
#include "msg_0x21_entitylookandrelativemove_stc.h"
#include "msg_0x22_entityteleport_stc.h"
#include "msg_0x23_entityheadlook_stc.h"
#include "msg_0x26_entitystatus_stc.h"
#include "msg_0x27_attachentity_stc.h"
#include "msg_0x28_entitymetadata_stc.h"
#include "msg_0x29_entityeffect_stc.h"
#include "msg_0x2a_removeentityeffect_stc.h"
#include "msg_0x2b_setexperience_stc.h"
#include "msg_0x33_chunkdata_stc.h"
#include "msg_0x34_multiblockchange_stc.h"
#include "msg_0x35_blockchange_stc.h"
#include "msg_0x36_blockaction_stc.h"
#include "msg_0x37_blockbreakanimation_stc.h"
#include "msg_0x38_mapchunkbulk_stc.h"
#include "msg_0x3c_explosion_stc.h"
#include "msg_0x3d_soundorparticleeffect_stc.h"
#include "msg_0x3e_namedsoundeffect_stc.h"
#include "msg_0x3f_particle_stc.h"
#include "msg_0x46_changegamestate_stc.h"
#include "msg_0x47_spawnglobalentity_stc.h"
#include "msg_0x64_openwindow_stc.h"
#include "msg_0x65_closewindow_tw.h"
#include "msg_0x66_clickwindow_stc.h"
#include "msg_0x67_setslot_stc.h"
#include "msg_0x68_setwindowitems_stc.h"
#include "msg_0x69_updatewindowproperty_stc.h"
#include "msg_0x6a_confirmtransaction_tw.h"
#include "msg_0x6b_creativeinventoryaction_tw.h"
#include "msg_0x6c_encnahtitem_stc.h"
#include "msg_0x82_updatesign_tw.h"
#include "msg_0x83_itemdata_stc.h"
#include "msg_0x84_updatetileentity_stc.h"
#include "msg_0xc8_incrementstatistic_stc.h"
#include "msg_0xc9_playerlistitem_stc.h"
#include "msg_0xca_playerabilities_tw.h"
#include "msg_0xcb_tabcomplete_tw.h"
#include "msg_0xcc_clientsettings_cts.h"
#include "msg_0xcd_clientstatuses_cts.h"
#include "msg_0xce_scoreboardobjective_stc.h"
#include "msg_0xcf_updatescore_stc.h"
#include "msg_0xd0_displayscoreboard_stc.h"
#include "msg_0xd1_teams_stc.h"
#include "msg_0xfa_pluginmessage_tw.h"
#include "msg_0xfc_encryptionkeyresponse_tw.h"
#include "msg_0xfd_encryptionkeyrequest_stc.h"
#include "msg_0xff_disconnect_tw.h"


#endif // _MCPROTOCOL_MSGS_H_