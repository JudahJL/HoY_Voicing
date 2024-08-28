#include "hook.h"
#include "log.h"

void MessageHandler(SKSE::MessagingInterface::Message* a_msg) {
	switch (a_msg->type) {
		case SKSE::MessagingInterface::kDataLoaded:
			hooks::on_animation_event::install();
			break;
		default:
			break;
	}
}

SKSEPluginLoad(const SKSE::LoadInterface* skse) {
	SKSE::Init(skse);
	SetupLog();
	RE::BSAnimationGraphEvent;
	const auto* const messaging{ SKSE::GetMessagingInterface() };
	if (messaging != nullptr && !messaging->RegisterListener("SKSE", MessageHandler)) {
		return false;
	}

	return true;
}