
FIND_PACKAGE(Qt4 REQUIRED COMPONENTS QtGui QtCore)
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(-W -Wall ${QT_DEFINITIONS})

SET(CE_SRCS
  attached_files_model.cc
  compose_email.cc
  main.cc
)

SET(CE_MOC_HDRS
  compose_email.h
)
QT4_WRAP_CPP(CE_MOC_SRCS ${CE_MOC_HDRS})

QT4_ADD_RESOURCES(CE_QRC_SRCS compose_email.qrc)

#QT4_WRAP_UI(CE_UI_HEADERS ${CE_UIS})

QT4_ADD_TRANSLATION(CE_QM
  compose_email_de.ts
  compose_email_es.ts
  compose_email_nb.ts
  compose_email_ru.ts
  compose_email_sv.ts
)

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
