#include "ClibUtil/editorID.hpp"
#include "hook.h"
#include "util.h"

namespace hooks {
	void on_animation_event::install() {
		REL::Relocation<uintptr_t> AnimEventVtbl_NPC{ RE::VTABLE_Character[2] };
		_ProcessEvent_NPC = AnimEventVtbl_NPC.write_vfunc(0x1, ProcessEvent_NPC);
		logger::info("hook:on_animation_event");
	}

	void on_animation_event::GetEquippedShout(const RE::Actor* actor, bool SpellFire) {
		auto* const limbo_shout{ actor->GetActorRuntimeData().selectedPower };

		if(limbo_shout && limbo_shout->Is(RE::FormType::Shout)) {
			auto* const data{ RE::TESDataHandler::GetSingleton() };

			std::string limbo_shout_editor_id = clib_util::editorID::get_editorID(limbo_shout);
			logger::trace("Actor {} Shout {}", actor->GetName(), limbo_shout_editor_id);

			switch(hash(limbo_shout_editor_id.c_str(), limbo_shout_editor_id.size())) {
				case "HoY_BendWillShout_Miraak"_h:
					util::playSound(actor, data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'57 : 0x8'55, "Heroes of Yore.esp"));
					break;

				case "HoY_DragonAspectShout_Miraak"_h:
					util::playSound(actor, data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'59 : 0x8'58, "Heroes of Yore.esp"));
					break;

				case "HoY_SonicShieldShout_Miraak"_h:
					util::playSound(actor, data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'54 : 0x8'53, "Heroes of Yore.esp"));
					break;

				case "HoY_PullofNirnShout_Miraak"_h:
					util::playSound(actor, data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'56 : 0x8'55, "Heroes of Yore.esp"));
					break;

				case "HoY_MarkedForDeathShout_Miraak"_h:
					util::playSound(actor, data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'5D : 0x8'5C, "Heroes of Yore.esp"));
					break;

				case "HoY_DisarmShout_Gormlaith"_h:
					util::playSound(actor, data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'87 : 0x8'86, "Heroes of Yore.esp"));
					break;

				case "HoY_DisarmShout_Greybeard"_h:
					util::playSound(actor, data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'75 : 0x8'74, "Heroes of Yore.esp"));
					break;

				case "HoY_DisarmShout_Ulfric"_h:
					util::playSound(actor, data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'B5 : 0x8'B4, "Heroes of Yore.esp"));
					break;

				case "HoY_DisarmShout_EbonyWarrior"_h:
					util::playSound(actor, data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'B9 : 0x8'B8, "Heroes of Yore.esp"));
					break;

				case "HoY_FireBreathShout_Gormlaith"_h:
					util::playSound(actor, data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'89 : 0x8'88, "Heroes of Yore.esp"));
					break;

				case "HoY_FireBreathShout_Felldir"_h:
					util::playSound(actor, data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'95 : 0x8'94, "Heroes of Yore.esp"));
					break;

				case "HoY_FireBreathShout_Miraak"_h:
					util::playSound(actor, data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'50 : 0x8'4F, "Heroes of Yore.esp"));
					break;

				case "HoY_FireBreathShout_GreyBeard"_h:
					util::playSound(actor, data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'77 : 0x8'76, "Heroes of Yore.esp"));
					break;

				case "HoY_FireBreathShout_PhantomFelldir"_h:
					util::playSound(actor, data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'95 : 0x8'94, "Heroes of Yore.esp"));
					break;

				case "HoY_MoonBlastShout_Miraak"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'6D : 0x8'6C, "Heroes of Yore.esp")));
					break;

				case "HoY_DevourSoulShout_Miraak"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'63 : 0x8'62, "Heroes of Yore.esp")));
					break;

				case "MQ105PhantomFormShout"_h:
				case "HoY_PhantomFormShout_GreyBeard"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'7B : 0x8'7A, "Heroes of Yore.esp")));
					break;

				case "HoY_PhantomFormShout_Felldir"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'9B : 0x8'9A, "Heroes of Yore.esp")));
					break;

				case "HoY_CycloneShout_Miraak"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'65 : 0x8'64, "Heroes of Yore.esp")));
					break;

				case "HoY_CycloneShout_Felldir"_h:
				case "HoY_CycloneShout_PhantomFelldir"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'99 : 0x8'98, "Heroes of Yore.esp")));
					break;

				case "HoY_ApocryphalCataclysmShout_Miraak"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'67 : 0x8'66, "Heroes of Yore.esp")));
					break;

				case "HoY_IceFormShout_Gormlaith"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'85 : 0x8'84, "Heroes of Yore.esp")));
					break;

				case "HoY_IceFormShout_GreyBeard"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'73 : 0x8'72, "Heroes of Yore.esp")));
					break;

				case "HoY_ClearSkiesShout_Felldir"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'A1 : 0x8'A0, "Heroes of Yore.esp")));
					break;

				case "HoY_ClearSkiesShout_Gormlaith"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'91 : 0x8'90, "Heroes of Yore.esp")));
					break;

				case "HoY_ClearSkiesShout_Hakon"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'B1 : 0x8'B0, "Heroes of Yore.esp")));
					break;

				case "HoY_ClearSkiesShout_GreyBeard"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'7D : 0x8'7C, "Heroes of Yore.esp")));
					break;

				case "HoY_DismayShout_Hakon"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'A5 : 0x8'A4, "Heroes of Yore.esp")));
					break;

				case "HoY_Dismay_GreyBeard"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'71 : 0x8'70, "Heroes of Yore.esp")));
					break;

				case "HoY_DismayShout_Gormlaith"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x68'42 : 0x68'41, "Heroes of Yore.esp")));
					break;

				case "HoY_ShockBreathShout_Felldir"_h:
				case "HoY_ShockBreathShout_PhantomFelldir"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'97 : 0x8'96, "Heroes of Yore.esp")));
					break;

				case "HoY_ShockBreathShout_Hakon"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'A7 : 0x8'A6, "Heroes of Yore.esp")));
					break;

				case "HoY_ShockBreathShout_Miraak"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'5F : 0x8'5E, "Heroes of Yore.esp")));
					break;

				case "HoY_ElementalFuryShout_Hakon"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'AD : 0x8'AC, "Heroes of Yore.esp")));
					break;

				case "HoY_ElementalFuryShout_Miraak"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'6B : 0x8'6A, "Heroes of Yore.esp")));
					break;

				case "HoY_ElementalFuryShout_GreyBeard"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'7F : 0x8'7E, "Heroes of Yore.esp")));
					break;

				case "HoY_WhirlwindSprintShout_Miraak"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'5B : 0x8'5A, "Heroes of Yore.esp")));
					break;

				case "HoY_WhirlwindSprintShout_GreyBeard"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'81 : 0x8'80, "Heroes of Yore.esp")));
					break;

				case "HoY_WhirlwindSprintShout_Hakon"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x68'4A : 0x68'49, "Heroes of Yore.esp")));
					break;

				case "HoY_DragonrendShout_Gormlaith"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'8F : 0x8'8E, "Heroes of Yore.esp")));
					break;

				case "HoY_DragonrendShout_Felldir"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'9F : 0x8'9E, "Heroes of Yore.esp")));
					break;

				case "HoY_DragonrendShout_Hakon"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'AF : 0x8'AE, "Heroes of Yore.esp")));
					break;

				case "HoY_SkyShiftShout_Miraak"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'69 : 0x8'68, "Heroes of Yore.esp")));
					break;

				case "HoY_FrostBreathShout_Gormlaith"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'8B : 0x8'8A, "Heroes of Yore.esp")));
					break;

				case "HoY_FrostBreathShout_Hakon"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'A9 : 0x8'A8, "Heroes of Yore.esp")));
					break;

				case "HoY_FrostBreathShout_Miraak"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'52 : 0x8'51, "Heroes of Yore.esp")));
					break;

				case "HoY_FrostBreathShout_GreyBeard"_h:
				case "HoY_FrostBreathShout_PhantomGreyBeard"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'79 : 0x8'78, "Heroes of Yore.esp")));
					break;

				case "HoY_UnrelentingForceShout_Gormlaith"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'83 : 0x8'82, "Heroes of Yore.esp")));
					break;

				case "HoY_UnrelentingForceShout_Felldir"_h:
				case "HoY_UnrelentingForceShout_PhantomFelldir"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'93 : 0x8'92, "Heroes of Yore.esp")));
					break;

				case "HoY_UnrelentingForceShout_Hakon"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'A3 : 0x8'A2, "Heroes of Yore.esp")));
					break;

				case "HoY_UnrelentingForceShout_Miraak"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'4D : 0x8'4C, "Heroes of Yore.esp")));
					break;

				case "HoY_UnrelentingForceShout_EbonyWarrior"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'B7 : 0x8'B6, "Heroes of Yore.esp")));
					break;

				case "HoY_UnrelentingForceShout_GreyBeard"_h:
				case "HoY_UnrelentingForceShout_PhantomGreyBeard"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'6F : 0x8'6E, "Heroes of Yore.esp")));
					break;

				case "HoY_UnrelentingForceShout_Tsun"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'BB : 0x8'BA, "Heroes of Yore.esp")));
					break;

				case "HoY_UnrelentingForceShout_Ulfric"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'B3 : 0x8'B2, "Heroes of Yore.esp")));
					break;

				case "HoY_ThuumSeekShout_Miraak"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x68'7B : 0x68'7A, "Heroes of Yore.esp")));
					break;

				case "HoY_ThuumSeekShout_Felldir"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x68'44 : 0x68'43, "Heroes of Yore.esp")));
					break;

				case "HoY_BecomeEtherealShout_Gormlaith"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'8D : 0x8'8C, "Heroes of Yore.esp")));
					break;

				case "HoY_BecomeEtherealShout_Hakon"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'AB : 0x8'AA, "Heroes of Yore.esp")));
					break;

				case "HoY_BecomeEtherealShout_Miraak"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'61 : 0x8'60, "Heroes of Yore.esp")));
					break;

				case "HoY_DrainVitalityShout_Felldir"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x8'9D : 0x8'9C, "Heroes of Yore.esp")));
					break;

				case "HoY_MirrorMissilesShout_Felldir"_h:
					util::playSound(actor, (data->LookupForm<RE::BGSSoundDescriptorForm>(SpellFire ? 0x68'A4 : 0x68'A3, "Heroes of Yore.esp")));
					break;

				default:
					break;
			}
		}
	}

	void on_animation_event::ProcessEvent(RE::BSTEventSink<RE::BSAnimationGraphEvent>*, RE::BSAnimationGraphEvent* a_event, RE::BSTEventSource<RE::BSAnimationGraphEvent>* a_eventSource) {
		if(!a_event->holder) { return; }
		const std::string_view eventTag{ a_event->tag.data() };
		const auto* const      actor    = a_event->holder->As<RE::Actor>();
		switch(hash(eventTag.data(), eventTag.size())) {
			case "BeginCastVoice"_h:
				GetEquippedShout(actor);
				break;
			case "Voice_SpellFire_Event"_h:
				GetEquippedShout(actor, true);
				break;
			default:
				break;
		}
	}

	EventResult on_animation_event::ProcessEvent_NPC(RE::BSTEventSink<RE::BSAnimationGraphEvent>* a_sink, RE::BSAnimationGraphEvent* a_event, RE::BSTEventSource<RE::BSAnimationGraphEvent>* a_eventSource) {
		ProcessEvent(a_sink, a_event, a_eventSource);
		return _ProcessEvent_NPC(a_sink, a_event, a_eventSource);
	}

	auto util::playSound(const RE::Actor* a_actor, BSISoundDescriptor* a_descriptor) -> void {
		RE::BSSoundHandle handle;
		handle.soundID            = static_cast<uint32_t>(-1);
		handle.assumeSuccess      = false;
		handle.state.set(RE::BSSoundHandle::AssumedState::kInitialized);

		RE::BSAudioManager::GetSingleton()->BuildSoundDataFromDescriptor(handle, a_descriptor, 16);

		if(handle.SetPosition(a_actor->data.location)) {
			handle.SetObjectToFollow(a_actor->Get3D());
			handle.Play();
		}
	}
}  // namespace hooks
