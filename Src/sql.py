import sqlite3
import base64
from readxml import Schedule


schedule = sqlite3.connect(
    "{}.db".format(Schedule(Name="小张", XML_url="../Docs/NewSimple.xml").id())
)
shuju = Schedule(Name="小张", XML_url="../Docs/NewSimple.xml")

# 数据定义部分
schedule.cursor().execute(
    """CREATE TABLE if not exists HEAD
    (   KEY         TEXT    PRIMARY KEY     NOT NULL,
        VALUE       TEXT                    NOT NULL);"""
)

schedule.cursor().execute(
    """CREATE TABLE if not exists BODY
    (   ID          INTEGER PRIMARY KEY AUTOINCREMENT     NOT NULL,
        LESSON_NAME TEXT                    NOT NULL, 
        WHATDAY     INT                     NOT NULL,
        WEEK_LIST   TEXT                    NOT NULL,
        CLASS_LIST  TEXT                    NOT NULL,
        LOCATION    TEXT                    NOT NULL,
        TYPE        TEXT                    NOT NULL,
        TEACHER     TEXT                    NOT NULL,
        OTHER       TEXT);"""
)


# 导入全部数据
# 重复执行会报错，因为没有校验是否已经存在
# 个人信息部分
schedule.cursor().execute(
    "INSERT INTO HEAD (KEY,VALUE) \
      VALUES ('STUDENT_NAME', '{}');".format(
        shuju.name()
    )
)
schedule.cursor().execute(
    "INSERT INTO HEAD (KEY,VALUE) \
      VALUES ('STUDENT_ID', '{}');".format(
        shuju.id()
    )
)
schedule.cursor().execute(
    "INSERT INTO HEAD (KEY,VALUE) \
      VALUES ('MAJOR', '{}');".format(
        shuju.major()
    )
)
schedule.cursor().execute(
    "INSERT INTO HEAD (KEY,VALUE) \
      VALUES ('CLASS', '{}');".format(
        shuju.studentclass()
    )
)
for i in range(0, shuju.lesson_num()):
    schedule.cursor().execute(
        "INSERT INTO BODY (LESSON_NAME,WHATDAY,WEEK_LIST,CLASS_LIST,LOCATION,TYPE,TEACHER,OTHER) \
             VALUES ('{}', {},'{}', '{}', '{}', '{}', '{}', '{}');".format(
            str(shuju.LESSON[i]),
            shuju.lesson(i, "WHATDAY"),
            shuju.lesson(i, "WEEKLIST"),
            shuju.lesson(i, "CLASSLIST"),
            shuju.lesson(i, "LOCATION"),
            shuju.lesson(i, "TYPE"),
            shuju.lesson(i, "TEACHER"),
            shuju.lesson(i, "OTHER"),
        )
    )


# 保存更改
schedule.commit()
