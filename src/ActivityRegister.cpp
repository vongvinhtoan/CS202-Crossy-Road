#include <Application.hpp>
#include <ActivityList.hpp>

void Application::registerActivities()
{
	m_activityStack->registerActivity<MainActivity>(ActivityID::Main);
	m_activityStack->registerActivity<LoadingActivity>(ActivityID::Loading);
	m_activityStack->registerActivity<HomeActivity>(ActivityID::Home);
	m_activityStack->registerActivity<InstructionActivity>(ActivityID::Instruction);
	m_activityStack->registerActivity<CharacterActivity>(ActivityID::Character);
	m_activityStack->registerActivity<SettingActivity>(ActivityID::Setting);
	m_activityStack->registerActivity<PlaygroundActivity>(ActivityID::Playground);
	m_activityStack->registerActivity<PauseActivity>(ActivityID::Pause);
	m_activityStack->registerActivity<GameOverActivity>(ActivityID::GameOver);
}
