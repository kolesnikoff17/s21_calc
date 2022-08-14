CC = gcc
CFLAGS = -pipe -O2 $(EXPORT_ARCH_ARGS) -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk -mmacosx-version-min=11 -Wall -Wextra -g -fPIC $(DEFINES)
CXXFLAGS      = -pipe -stdlib=libc++ -O2 -std=gnu++1z $(EXPORT_ARCH_ARGS) -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk -mmacosx-version-min=11 -Wall -Wextra -fPIC $(DEFINES)
INCPATH       = -Icalc_qt -I. -I/usr/local/lib/QtPrintSupport.framework/Headers -I/usr/local/lib/QtWidgets.framework/Headers -I/usr/local/lib/QtGui.framework/Headers -I/usr/local/lib/QtCore.framework/Headers -I. -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk/System/Library/Frameworks/OpenGL.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk/System/Library/Frameworks/AGL.framework/Headers -I. -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk/System/Library/Frameworks/OpenGL.framework/Headers -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk/System/Library/Frameworks/AGL.framework/Headers -I/usr/local/share/qt/mkspecs/macx-clang -F/usr/local/lib
DEFINES       = -DQT_NO_DEBUG -DQT_PRINTSUPPORT_LIB -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
LFLAGS        = -stdlib=libc++ -headerpad_max_install_names $(EXPORT_ARCH_ARGS) -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk -mmacosx-version-min=11 -Wl,-rpath,@executable_path/../Frameworks -Wl,-rpath,/usr/local/lib
LIBS          = $(SUBLIBS) -F/usr/local/lib -framework QtPrintSupport -framework ApplicationServices -framework QtWidgets -framework QtGui -framework AppKit -framework ImageIO -framework Metal -framework QtCore -framework DiskArbitration -framework IOKit -lcups -framework AGL -framework OpenGL   

GCOV_FLAGS := -fprofile-arcs -ftest-coverage
LDFLAGS := -fprofile-arcs --coverage
LCHECK = -lcheck
LIN_FLAGS := -lpthread -pthread -lrt -lm -lsubunit
ifeq ($(shell uname), Linux)
LCHECK += $(LIN_FLAGS)
endif

SOURCES_TEST:= $(wildcard calculating/*.c) $(wildcard bonus/*.c)

SOURCES       = calculating/parsing.c \
		calculating/calc_core.c \
		calculating/common.c \
		bonus/credit_c.c \
		bonus/deposit_c.c \
		qcustomplot-source/qcustomplot.cpp \
		calc_qt/credit.cpp \
		calc_qt/deposit.cpp \
		calc_qt/main.cpp \
		calc_qt/calc.cpp \
		calc_qt/plot.cpp moc_qcustomplot.cpp \
		moc_calc.cpp \
		moc_credit.cpp \
		moc_deposit.cpp \
		moc_plot.cpp
OBJECTS       = parsing.o \
		calc_core.o \
		common.o \
		credit_c.o \
		deposit_c.o \
		qcustomplot.o \
		credit.o \
		deposit.o \
		main.o \
		calc.o \
		plot.o \
		moc_qcustomplot.o \
		moc_calc.o \
		moc_credit.o \
		moc_deposit.o \
		moc_plot.o
DIST          = /usr/local/share/qt/mkspecs/features/spec_pre.prf \
		/usr/local/share/qt/mkspecs/features/device_config.prf \
		/usr/local/share/qt/mkspecs/common/unix.conf \
		/usr/local/share/qt/mkspecs/common/mac.conf \
		/usr/local/share/qt/mkspecs/common/macx.conf \
		/usr/local/share/qt/mkspecs/common/sanitize.conf \
		/usr/local/share/qt/mkspecs/common/gcc-base.conf \
		/usr/local/share/qt/mkspecs/common/gcc-base-mac.conf \
		/usr/local/share/qt/mkspecs/common/clang.conf \
		/usr/local/share/qt/mkspecs/common/clang-mac.conf \
		/usr/local/share/qt/mkspecs/qconfig.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3danimation.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3danimation_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3dcore.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3dcore_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3dextras.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3dextras_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3dinput.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3dinput_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3dlogic.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3dlogic_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3dquick.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3dquick_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3dquickanimation.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3dquickanimation_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3dquickextras.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3dquickextras_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3dquickinput.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3dquickinput_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3dquickrender.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3dquickrender_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3dquickscene2d.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3dquickscene2d_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3drender.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_3drender_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_bluetooth.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_bluetooth_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_bodymovin_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_charts.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_charts_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_chartsqml.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_chartsqml_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_coap.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_coap_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_core.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_core5compat.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_core5compat_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_core_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_datavisualization.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_datavisualization_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_dbus.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_designer.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_designer_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_designercomponents_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_gui.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_help.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_help_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_hunspellinputmethod_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_labsanimation.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_labsanimation_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_labsfolderlistmodel.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_labsfolderlistmodel_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_labsqmlmodels.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_labsqmlmodels_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_labssettings.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_labssettings_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_labssharedimage.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_labssharedimage_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_labswavefrontmesh.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_labswavefrontmesh_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_linguist.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_linguist_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_mqtt.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_mqtt_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_multimedia.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_multimedia_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_multimediaquick_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_multimediawidgets.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_network.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_network_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_networkauth.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_networkauth_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_nfc.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_nfc_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_opcua.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_opcua_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_opengl.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_openglwidgets.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_openglwidgets_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_positioning.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_positioning_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_positioningquick.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_positioningquick_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_qml.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_qml_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_qmlcompiler_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_qmlcore.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_qmlcore_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_qmldebug_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_qmldom_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_qmllocalstorage.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_qmllocalstorage_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_qmlmodels.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_qmlmodels_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_qmltest_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_qmlworkerscript.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_qmlworkerscript_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_qmlxmllistmodel.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_qmlxmllistmodel_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quick.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quick3d.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quick3d_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quick3dassetimport.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quick3dassetimport_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quick3dassetutils.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quick3dassetutils_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quick3deffects.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quick3deffects_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quick3dhelpers.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quick3dhelpers_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quick3diblbaker.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quick3diblbaker_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quick3dparticles.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quick3dparticles_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quick3druntimerender.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quick3druntimerender_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quick3dutils.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quick3dutils_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quick_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quickcontrols2.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quickcontrols2impl.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quickcontrols2impl_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quickcontrolstestutilsprivate_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quickdialogs2.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quickdialogs2_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quickdialogs2quickimpl.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quickdialogs2quickimpl_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quickdialogs2utils.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quickdialogs2utils_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quicklayouts.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quicklayouts_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quickparticles_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quickshapes_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quicktemplates2.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quicktestutilsprivate_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quicktimeline.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quicktimeline_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_remoteobjects.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_remoteobjects_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_remoteobjectsqml.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_remoteobjectsqml_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_repparser.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_repparser_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_scxml.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_scxml_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_scxmlqml.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_scxmlqml_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_sensors.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_sensors_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_sensorsquick.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_sensorsquick_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_serialbus.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_serialbus_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_serialport.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_serialport_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_shadertools.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_shadertools_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_sql.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_statemachine.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_statemachine_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_statemachineqml.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_statemachineqml_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_svg.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_svg_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_svgwidgets.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_svgwidgets_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_testlib.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_tools_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_uiplugin.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_uitools.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_uitools_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_virtualkeyboard.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_virtualkeyboard_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_webchannel.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_webchannel_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_webenginecore.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_webenginecore_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_webenginequick.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_webenginequick_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_webenginequickdelegatesqml.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_webenginequickdelegatesqml_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_webenginewidgets.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_webenginewidgets_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_websockets.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_websockets_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_webview.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_webview_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_webviewquick.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_webviewquick_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_widgets.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_xml.pri \
		/usr/local/share/qt/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/local/share/qt/mkspecs/features/qt_functions.prf \
		/usr/local/share/qt/mkspecs/features/qt_config.prf \
		/usr/local/share/qt/mkspecs/macx-clang/qmake.conf \
		/usr/local/share/qt/mkspecs/features/spec_post.prf \
		/usr/local/share/qt/mkspecs/features/exclusive_builds.prf \
		/usr/local/share/qt/mkspecs/features/mac/sdk.prf \
		/usr/local/share/qt/mkspecs/features/toolchain.prf \
		/usr/local/share/qt/mkspecs/features/mac/toolchain.prf \
		/usr/local/share/qt/mkspecs/features/default_pre.prf \
		/usr/local/share/qt/mkspecs/features/mac/default_pre.prf \
		/usr/local/share/qt/mkspecs/features/resolve_config.prf \
		/usr/local/share/qt/mkspecs/features/default_post.prf \
		/usr/local/share/qt/mkspecs/features/mac/default_post.prf \
		/usr/local/share/qt/mkspecs/features/mac/objective_c.prf \
		/usr/local/share/qt/mkspecs/features/mac/mac.prf \
		/usr/local/share/qt/mkspecs/features/warn_on.prf \
		/usr/local/share/qt/mkspecs/features/qt.prf \
		/usr/local/share/qt/mkspecs/features/resources_functions.prf \
		/usr/local/share/qt/mkspecs/features/resources.prf \
		/usr/local/share/qt/mkspecs/features/moc.prf \
		/usr/local/share/qt/mkspecs/features/unix/opengl.prf \
		/usr/local/share/qt/mkspecs/features/uic.prf \
		/usr/local/share/qt/mkspecs/features/unix/thread.prf \
		/usr/local/share/qt/mkspecs/features/qmake_use.prf \
		/usr/local/share/qt/mkspecs/features/file_copies.prf \
		/usr/local/share/qt/mkspecs/features/mac/rez.prf \
		/usr/local/share/qt/mkspecs/features/mac/asset_catalogs.prf \
		/usr/local/share/qt/mkspecs/features/testcase_targets.prf \
		/usr/local/share/qt/mkspecs/features/exceptions.prf \
		/usr/local/share/qt/mkspecs/features/yacc.prf \
		/usr/local/share/qt/mkspecs/features/lex.prf \
		calc_qt/calc_qt.pro qcustomplot-source/qcustomplot.h \
		calc_qt/WindowSwitch.h \
		calc_qt/calc.h \
		calc_qt/credit.h \
		calc_qt/deposit.h \
		calc_qt/plot.h \
		calc_c.h calculating/parsing.c \
		calculating/calc_core.c \
		calculating/common.c \
		bonus/credit_c.c \
		bonus/deposit_c.c \
		qcustomplot-source/qcustomplot.cpp \
		calc_qt/credit.cpp \
		calc_qt/deposit.cpp \
		calc_qt/main.cpp \
		calc_qt/calc.cpp \
		calc_qt/plot.cpp 

DISTNAME := calc_qt1.0.0
OBJ_GCOV_DIR := obj_gcov
OBJECTS_GCOV := $(addprefix obj_gcov/,$(SOURCES_TEST:.c=.o))
HEADER = calc_c.h
TARGET = build/app

RM := rm -rf


all: install

install: ui_calc.h ui_credit.h ui_deposit.h ui_plot.h $(OBJECTS)  
	@test -d build/ || mkdir -p build/
	clang++ $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

uninstall: 
	$(RM) build

create_dir:
	@mkdir -p $(OBJ_GCOV_DIR)

test: tests/test_calc.c $(HEADER) $(OBJECTS_GCOV)
	$(CC) $(CFLAGS) $< $(OBJ_GCOV_DIR)/*.o -o $@ $(LCHECK) $(LDFLAGS) $(GCOV_FLAGS)
	./$@
	@mv *gcda *gcno $(OBJ_GCOV_DIR)/

gcov_report: test
	@rm -f $(OBJ_GCOV_DIR)/*tests*
	@lcov/bin/./lcov -c -d $(OBJ_GCOV_DIR)/. -o $(OBJ_GCOV_DIR)/coverage.info
	@lcov/bin/./genhtml $(OBJ_GCOV_DIR)/coverage.info --output-directory out

$(OBJ_GCOV_DIR)/%.o: %.c $(HEADER) create_dir
	@$(CC) $(CFLAGS) $(GCOV_FLAGS) -c $< -o obj_gcov/$(subst /,_,$@)
	# @mv *.o *gcno $(OBJ_GCOV_DIR)/

moc_qcustomplot.cpp: qcustomplot-source/qcustomplot.h \
		/usr/local/lib/QtCore.framework/Headers/qmath.h \
		/usr/local/lib/QtCore.framework/Headers/qnumeric.h \
		/usr/local/lib/QtCore.framework/Headers/QtNumeric \
		moc_predefs.h \
		/usr/local/share/qt/libexec/moc
	/usr/local/share/qt/libexec/moc $(DEFINES) --include moc_predefs.h -I/usr/local/share/qt/mkspecs/macx-clang -Icalc_qt -I/usr/local/lib/QtPrintSupport.framework/Headers -I/usr/local/lib/QtWidgets.framework/Headers -I/usr/local/lib/QtGui.framework/Headers -I/usr/local/lib/QtCore.framework/Headers -I. -I/usr/local/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/13.0.0/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk/usr/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -F/usr/local/lib qcustomplot-source/qcustomplot.h -o moc_qcustomplot.cpp

moc_calc.cpp: calc_qt/calc.h \
		/usr/local/lib/QtWidgets.framework/Headers/QMainWindow \
		/usr/local/lib/QtWidgets.framework/Headers/qmainwindow.h \
		calc_qt/WindowSwitch.h \
		calc_c.h \
		moc_predefs.h \
		/usr/local/share/qt/libexec/moc
	/usr/local/share/qt/libexec/moc $(DEFINES) --include moc_predefs.h -I/usr/local/share/qt/mkspecs/macx-clang -Icalc_qt -I/usr/local/lib/QtPrintSupport.framework/Headers -I/usr/local/lib/QtWidgets.framework/Headers -I/usr/local/lib/QtGui.framework/Headers -I/usr/local/lib/QtCore.framework/Headers -I. -I/usr/local/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/13.0.0/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk/usr/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -F/usr/local/lib calc_qt/calc.h -o moc_calc.cpp

moc_credit.cpp: calc_qt/credit.h \
		/usr/local/lib/QtWidgets.framework/Headers/QMainWindow \
		/usr/local/lib/QtWidgets.framework/Headers/qmainwindow.h \
		calc_qt/WindowSwitch.h \
		calc_c.h \
		moc_predefs.h \
		/usr/local/share/qt/libexec/moc
	/usr/local/share/qt/libexec/moc $(DEFINES) --include moc_predefs.h -I/usr/local/share/qt/mkspecs/macx-clang -Icalc_qt -I/usr/local/lib/QtPrintSupport.framework/Headers -I/usr/local/lib/QtWidgets.framework/Headers -I/usr/local/lib/QtGui.framework/Headers -I/usr/local/lib/QtCore.framework/Headers -I. -I/usr/local/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/13.0.0/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk/usr/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -F/usr/local/lib calc_qt/credit.h -o moc_credit.cpp

moc_deposit.cpp: calc_qt/deposit.h \
		/usr/local/lib/QtWidgets.framework/Headers/QMainWindow \
		/usr/local/lib/QtWidgets.framework/Headers/qmainwindow.h \
		calc_qt/WindowSwitch.h \
		calc_c.h \
		moc_predefs.h \
		/usr/local/share/qt/libexec/moc
	/usr/local/share/qt/libexec/moc $(DEFINES) --include moc_predefs.h -I/usr/local/share/qt/mkspecs/macx-clang -Icalc_qt -I/usr/local/lib/QtPrintSupport.framework/Headers -I/usr/local/lib/QtWidgets.framework/Headers -I/usr/local/lib/QtGui.framework/Headers -I/usr/local/lib/QtCore.framework/Headers -I. -I/usr/local/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/13.0.0/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk/usr/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -F/usr/local/lib calc_qt/deposit.h -o moc_deposit.cpp

moc_plot.cpp: calc_qt/plot.h \
		/usr/local/lib/QtWidgets.framework/Headers/QMainWindow \
		/usr/local/lib/QtWidgets.framework/Headers/qmainwindow.h \
		qcustomplot-source/qcustomplot.h \
		/usr/local/lib/QtCore.framework/Headers/qmath.h \
		/usr/local/lib/QtCore.framework/Headers/qnumeric.h \
		/usr/local/lib/QtCore.framework/Headers/QtNumeric \
		calc_qt/WindowSwitch.h \
		calc_c.h \
		moc_predefs.h \
		/usr/local/share/qt/libexec/moc
	/usr/local/share/qt/libexec/moc $(DEFINES) --include moc_predefs.h -I/usr/local/share/qt/mkspecs/macx-clang -Icalc_qt -I/usr/local/lib/QtPrintSupport.framework/Headers -I/usr/local/lib/QtWidgets.framework/Headers -I/usr/local/lib/QtGui.framework/Headers -I/usr/local/lib/QtCore.framework/Headers -I. -I/usr/local/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk/usr/include/c++/v1 -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/clang/13.0.0/include -I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk/usr/include -I/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -F/usr/local/lib calc_qt/plot.h -o moc_plot.cpp

parsing.o: calculating/parsing.c calculating/parsing.h \
		calculating/common.h \
		calculating/stack.h \
		calc_c.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o parsing.o calculating/parsing.c

calc_core.o: calculating/calc_core.c calculating/calc_core.h \
		calculating/common.h \
		calculating/stack.h \
		calc_c.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o calc_core.o calculating/calc_core.c

common.o: calculating/common.c calculating/common.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o common.o calculating/common.c

credit_c.o: bonus/credit_c.c calc_c.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o credit_c.o bonus/credit_c.c

deposit_c.o: bonus/deposit_c.c calc_c.h
	$(CC) -c $(CFLAGS) $(INCPATH) -o deposit_c.o bonus/deposit_c.c

qcustomplot.o: qcustomplot-source/qcustomplot.cpp qcustomplot-source/qcustomplot.h \
		/usr/local/lib/QtCore.framework/Headers/qmath.h \
		/usr/local/lib/QtCore.framework/Headers/qnumeric.h \
		/usr/local/lib/QtCore.framework/Headers/QtNumeric
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qcustomplot.o qcustomplot-source/qcustomplot.cpp

credit.o: calc_qt/credit.cpp calc_qt/credit.h \
		/usr/local/lib/QtWidgets.framework/Headers/QMainWindow \
		/usr/local/lib/QtWidgets.framework/Headers/qmainwindow.h \
		calc_qt/WindowSwitch.h \
		calc_c.h \
		calc_qt/calc.h \
		calc_qt/plot.h \
		qcustomplot-source/qcustomplot.h \
		/usr/local/lib/QtCore.framework/Headers/qmath.h \
		/usr/local/lib/QtCore.framework/Headers/qnumeric.h \
		/usr/local/lib/QtCore.framework/Headers/QtNumeric \
		calc_qt/deposit.h \
		ui_credit.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o credit.o calc_qt/credit.cpp

deposit.o: calc_qt/deposit.cpp calc_qt/deposit.h \
		/usr/local/lib/QtWidgets.framework/Headers/QMainWindow \
		/usr/local/lib/QtWidgets.framework/Headers/qmainwindow.h \
		calc_qt/WindowSwitch.h \
		calc_c.h \
		calc_qt/calc.h \
		calc_qt/credit.h \
		calc_qt/plot.h \
		qcustomplot-source/qcustomplot.h \
		/usr/local/lib/QtCore.framework/Headers/qmath.h \
		/usr/local/lib/QtCore.framework/Headers/qnumeric.h \
		/usr/local/lib/QtCore.framework/Headers/QtNumeric \
		ui_deposit.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o deposit.o calc_qt/deposit.cpp

main.o: calc_qt/main.cpp /usr/local/lib/QtWidgets.framework/Headers/QApplication \
		/usr/local/lib/QtWidgets.framework/Headers/qapplication.h \
		calc_qt/calc.h \
		/usr/local/lib/QtWidgets.framework/Headers/QMainWindow \
		/usr/local/lib/QtWidgets.framework/Headers/qmainwindow.h \
		calc_qt/WindowSwitch.h \
		calc_c.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o calc_qt/main.cpp

calc.o: calc_qt/calc.cpp calc_qt/calc.h \
		/usr/local/lib/QtWidgets.framework/Headers/QMainWindow \
		/usr/local/lib/QtWidgets.framework/Headers/qmainwindow.h \
		calc_qt/WindowSwitch.h \
		calc_c.h \
		calc_qt/credit.h \
		calc_qt/plot.h \
		qcustomplot-source/qcustomplot.h \
		/usr/local/lib/QtCore.framework/Headers/qmath.h \
		/usr/local/lib/QtCore.framework/Headers/qnumeric.h \
		/usr/local/lib/QtCore.framework/Headers/QtNumeric \
		calc_qt/deposit.h \
		ui_calc.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o calc.o calc_qt/calc.cpp

plot.o: calc_qt/plot.cpp calc_qt/plot.h \
		/usr/local/lib/QtWidgets.framework/Headers/QMainWindow \
		/usr/local/lib/QtWidgets.framework/Headers/qmainwindow.h \
		qcustomplot-source/qcustomplot.h \
		/usr/local/lib/QtCore.framework/Headers/qmath.h \
		/usr/local/lib/QtCore.framework/Headers/qnumeric.h \
		/usr/local/lib/QtCore.framework/Headers/QtNumeric \
		calc_qt/WindowSwitch.h \
		calc_c.h \
		calc_qt/calc.h \
		calc_qt/credit.h \
		calc_qt/deposit.h \
		ui_plot.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o plot.o calc_qt/plot.cpp

moc_qcustomplot.o: moc_qcustomplot.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_qcustomplot.o moc_qcustomplot.cpp

moc_calc.o: moc_calc.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_calc.o moc_calc.cpp

moc_credit.o: moc_credit.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_credit.o moc_credit.cpp

moc_deposit.o: moc_deposit.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_deposit.o moc_deposit.cpp

moc_plot.o: moc_plot.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_plot.o moc_plot.cpp

ui_calc.h: calc_qt/calc.ui \
		/usr/local/share/qt/libexec/uic
	/usr/local/share/qt/libexec/uic calc_qt/calc.ui -o ui_calc.h

ui_credit.h: calc_qt/credit.ui \
		/usr/local/share/qt/libexec/uic
	/usr/local/share/qt/libexec/uic calc_qt/credit.ui -o ui_credit.h

ui_deposit.h: calc_qt/deposit.ui \
		/usr/local/share/qt/libexec/uic
	/usr/local/share/qt/libexec/uic calc_qt/deposit.ui -o ui_deposit.h

ui_plot.h: calc_qt/plot.ui \
		/usr/local/share/qt/libexec/uic \
		qcustomplot-source/qcustomplot.h \
		/usr/local/lib/QtCore.framework/Headers/qmath.h \
		/usr/local/lib/QtCore.framework/Headers/qnumeric.h \
		/usr/local/lib/QtCore.framework/Headers/QtNumeric
	/usr/local/share/qt/libexec/uic calc_qt/plot.ui -o ui_plot.h

moc_predefs.h: /usr/local/share/qt/mkspecs/features/data/dummy.cpp
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ -pipe -stdlib=libc++ -O2 -std=gnu++1z $(EXPORT_ARCH_ARGS) -isysroot /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX12.1.sdk -mmacosx-version-min=11 -Wall -Wextra -dM -E -o moc_predefs.h /usr/local/share/qt/mkspecs/features/data/dummy.cpp

clean:
	$(RM) $(OBJ_GCOV_DIR)
	$(RM) $(TARGET_EXEC) *.a out
	$(RM) *.gc* test .vscode test.dSYM
	$(RM) calc_qt1.0.0.tar.gz
	$(RM) moc_* ui_* *.o

dist: 
	tar -cf $(DISTNAME).tar $(DIST) && gzip -9f $(DISTNAME).tar

dvi:
	open doc.pdf

lint:
	cp ../materials/linters/CPPLINT.cfg ./
	python3 ../materials/linters/cpplint.py --extensions=c *.h *.c
	python3 ../materials/linters/cpplint.py --extensions=c \
	calculating/*.c calculating/*.c tests/*.c bonus/*.c
	python3 ../materials/linters/cpplint.py --extensions=cpp calc_qt/*.cpp calc_qt/*.h
	$(RM) CPPLINT.cfg

rebuild: clean all

.PHONY: all clean rebuild test lint create_dir gcov_report
	
