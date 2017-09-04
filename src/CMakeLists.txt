
FIND_PACKAGE(Qt5 REQUIRED COMPONENTS Widgets LinguistTools)
SET(QT_LIBRARIES Qt5::Widgets)
ADD_DEFINITIONS(-W -Wall ${QT_DEFINITIONS})

SET(CE_SRCS
  attached_files_model.cc
  compose_email.cc
  main.cc
)

SET(CE_MOC_HDRS
  compose_email.h
)
QT5_WRAP_CPP(CE_MOC_SRCS ${CE_MOC_HDRS})

SET(CE_TRANSLATIONS
  compose_email_de.ts
  compose_email_es.ts
  compose_email_nb.ts
  compose_email_ru.ts
  compose_email_sv.ts
)
QT5_CREATE_TRANSLATION(CE_QM
  ${CE_SRCS}
  ${CE_TRANSLATIONS}
)

SET(CE_RESOURCES compose_email.qrc)
SET(CE_GEN_RESOURCES compose_email_generated.qrc)
CONFIGURE_FILE(${CE_GEN_RESOURCES} ${CE_GEN_RESOURCES} COPYONLY)
qt5_add_resources(CE_QRC_SRCS ${CE_RESOURCES} ${CMAKE_CURRENT_BINARY_DIR}/${CE_GEN_RESOURCES})

ADD_EXECUTABLE(diana_compose_email
  ${CE_SRCS}
  ${CE_MOC_SRCS}
  ${CE_QM}
  ${CE_QRC_SRCS}
  ${CE_UIS}
)

TARGET_LINK_LIBRARIES(diana_compose_email
  ${QT_LIBRARIES}
)

INSTALL(TARGETS diana_compose_email DESTINATION bin)
