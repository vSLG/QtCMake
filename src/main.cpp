#include <QGuiApplication>
#include <QQmlComponent>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQuickStyle>

int main(int argc, char **argv) {
  QGuiApplication::setOrganizationName("FakeCompany");
  QGuiApplication::setApplicationName("Example");
  QGuiApplication::setApplicationVersion("0.1");
  QQuickStyle::setStyle("Fusion");

  QGuiApplication app(argc, argv);
  QQmlEngine     *engine = new QQmlEngine();
  QQmlContext    *ctx    = new QQmlContext(engine->rootContext());
  QQmlComponent   component(engine, QUrl("qrc:/MainWindow.qml"));

  QObject::connect(engine, &QQmlEngine::quit, QCoreApplication::quit);

  if (component.isError()) {
    for (const QQmlError &e : component.errors())
      qCritical("%s:%d:%d: %s",
                e.url().toString().toStdString().c_str(),
                e.line(),
                e.column(),
                e.description().toStdString().c_str());
    qFatal("Um ou mais erros ocorreram, saindo");
  }

  component.create(ctx);

  int ret = app.exec();
  delete ctx;
  delete engine;
  return ret;
}