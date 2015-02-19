/****************************************************
 *
 * Author: Akela1101 <akela1101@gmail.com>
 *
 ****************************************************/

#ifndef ApplicationNya_H
#define ApplicationNya_H

#include "SingletonNya.hpp"
#include "ConfigNya.hpp"

#include "Nya.hpp"


namespace Nya
{
	class Application : public QObject
	{
		Q_OBJECT

		friend void SystemSignalHandler(int iSignal);

	protected:
		QString appName;              /// имя приложения
		QString rootConfigDir;        /// путь к корню конфигов
		QString configDir;            /// путь к конфигу
		QString configFileFullName;   /// имя конфига вместе с путём
		QString logDir;               /// загружается из конфига в переменной LOG_DIR
		QString traceLogPath;         /// logDir + trace.log
		QString crashLogPath;         /// logDir + crash.log
		QString robotEmail;           /// e-mail для оповещений.
		Config config;                /// конфиг
		bool isDaemon;                /// демон/обычное приложение
		bool isRestartOnCrash;        /// перезапускаться ли при падании

	public:
		Application() : isDaemon(false), isRestartOnCrash(false) {}
		virtual ~Application() = 0;

		QString GetConfigDir() const { return configDir; }
		const Config& GetConfig() const { return config; }

		virtual bool Init(); /// обязательно вызывать после конструктора

	protected:
		virtual void Quit();

		void LoadConfig(QString configDir_ = "", QString configFileName = "");
		bool SaveConfig();
		void InitLogs();

	private slots:
		void OnQuit() { Quit(); }
	};
}

#endif // ApplicationNya_H
