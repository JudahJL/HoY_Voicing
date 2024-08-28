#pragma once

namespace hooks {

using EventResult = RE::BSEventNotifyControl;

class on_animation_event {
public:
	static void install();
	static void GetEquippedShout(const RE::Actor* actor, bool SpellFire = false);

private:
	static inline void ProcessEvent(RE::BSTEventSink<RE::BSAnimationGraphEvent> *a_sink,RE::BSAnimationGraphEvent *a_event,RE::BSTEventSource<RE::BSAnimationGraphEvent> *a_eventSource);
	static EventResult ProcessEvent_NPC(RE::BSTEventSink<RE::BSAnimationGraphEvent> *a_sink, RE::BSAnimationGraphEvent *a_event,RE::BSTEventSource<RE::BSAnimationGraphEvent> *a_eventSource);

	static inline REL::Relocation<decltype(ProcessEvent_NPC)> _ProcessEvent_NPC;

};

inline void alloc() { SKSE::AllocTrampoline(1 << 8); }

class util {
public:
	static auto playSound(const RE::Actor* a_actor, RE::BSISoundDescriptor* a_descriptor) -> void;
};
};  // namespace hooks

// auto a =
// RE::TESForm::LookupByEditorID<RE::BGSSoundDescriptorForm>("aaaUDDragonAISpell");
