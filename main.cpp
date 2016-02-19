#include <QApplication>
#include <QDesktopWidget>
#include <QQmlApplicationEngine>
#include <QWindow>
#include <QRenderAspect>
#include <QInputAspect>
#include <QQmlAspectEngine>
#include <QGuiApplication>
#include <window.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Window window;
    //Qt3D::QWindow window;
    Qt3D::Quick::QQmlAspectEngine engine;
    engine.aspectEngine( )->registerAspect( new Qt3D::QRenderAspect );
    engine.aspectEngine( )->registerAspect( new Qt3D::QInputAspect );
    engine.aspectEngine( )->initialize( );

    QVariantMap data;
    data.insert( QStringLiteral( "surface" ),
                 QVariant::fromValue( static_cast<QSurface*>( &window ) ) );
    data.insert( QStringLiteral( "eventSource" ),
                 QVariant::fromValue( &window ) );
    engine.aspectEngine( )->setData( data );
    engine.setSource( QUrl( "qrc:/main.qml" ) );
    window.show( );
    return app.exec( );
}

