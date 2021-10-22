import camelot
import re
import os
import json
import glob  # 找到PDF文件路径
import xlrd  # 需要1.2.0版本
import xlsxwriter


# 找到当前目录下的全部PDF文件
def find_pdf_files():
    pdfpath_list = glob.glob(r'*课表.pdf')
    return pdfpath_list


# 查询某个人的excle课表
def find_ones_xlsx():
    xlsx_list = glob.glob((str(find_pdf_files()[count])[:-4]) + r'*.xlsx')
    return xlsx_list


# 解析pdf文件名称，判断获取全部表格/指定页码表格
def file_name_analysis(file_path):
    """
    :return: pages_list页码组成的列表
    """

    pages_dict = {}
    for f_path, f_name in file_path.items():
        regex = r'_(\d+)+'
        re_result = re.findall(regex, f_name)
        if re_result:
            pages_dict[f_path] = re_result
        else:
            pages_dict[f_path] = "all"

    return pages_dict


# 判断输入是目录还是文件
def is_file_or_dir(path):
    """
    :return : 返回由文件路径与文件名组成的字典
    """
    files_path_dict = {}
    # 判断文件或目录是否存在
    if os.path.exists(path):
        if os.path.isdir(path):
            # root, dirs, files = os.walk(path)
            for files in os.listdir(path):
                if os.path.splitext(files)[1] == '.pdf':
                    files_path_dict[path + files] = files
        else:
            if os.path.splitext(path)[1] == '.pdf':
                files_path_dict[path] = os.path.split(path)[1]

    return files_path_dict


# 读取pdf中的表格
def load_pdf(page_dict):
    """
    :param page_dict:
    :return: 返回一个存储表格数据的字典
    """

    data_dict = {}
    for f_path, f_page in page_dict.items():
        if f_page == "all":
            tables = camelot.read_pdf(f_path, pages="all")
        else:
            for p in f_page:
                tables = camelot.read_pdf(f_path, pages=str(p))

        for t in tables:
            # 绘制表格图像
            # plt = camelot.plot(t, kind='grid')
            # plt.show()

            # 转换为json
            data = json.dumps(t.data)
            str_key = str(t.page) + "页第" + str(t.order) + "张表"
            data_dict[str_key] = data
            # 输出为excel
            t.to_excel(str(find_pdf_files()[count])[:-4] + "第" + str(t.page) + "页第" + str(t.order) + "张表" + '.xlsx')
            # 输出为csv
            # t.to_csv(str(t.page) + "页第" + str(t.order) + "张表" + '.cvs')
            # 输出为html
            # t.to_html(str(t.page) + "页第" + str(t.order) + "张表" + '.html')
            # 输出为json
            # t.to_json(str(t.page) + "页第" + str(t.order) + "张表" + '.json')

        # 获取第一个excel的sheet个数以及名字作为标准
        first_file_fh = open_xls(find_ones_xlsx()[0])
        first_file_sheet = first_file_fh.sheets()
        first_file_sheet_num = len(first_file_sheet)
        sheet_name = []
        for sheetname in first_file_sheet:
            sheet_name.append(sheetname.name)

        # 定义一个目标excel
        endxls = xlsxwriter.Workbook(str(find_pdf_files()[count])[:-4] + '.xlsx')

        all_sheet_value = []

        # 把所有内容都放到列表all_sheet_value中
        for sheet_num in range(0, first_file_sheet_num):
            all_sheet_value.append([])
            for file_name in find_ones_xlsx():
                print("正在读取" + file_name + "的第" + str(sheet_num + 1) + "个标签...")
                file_value = get_file_value(file_name, sheet_num)
                all_sheet_value[sheet_num].append(file_value)

        # print(all_sheet_value)

        num = 1
        sheet_index = -1

        # 将列表all_sheet_value的内容写入目标excel
        for sheet in all_sheet_value:
            sheet_index += 1
            end_xls_sheet = endxls.add_worksheet(sheet_name[sheet_index])
            num += 1
            num1 = -1
            for sheet1 in sheet:
                for sheet2 in sheet1:
                    num1 += 1
                    num2 = -1
                    for sheet3 in sheet2:
                        num2 += 1
                        # print(num,num1,num2,sheet3)
                        # 在第num1行的第num2列写入sheet3的内容
                        end_xls_sheet.write(num1, num2, sheet3)

        endxls.close()

    return data_dict


def open_xls(file):
    try:
        fh = xlrd.open_workbook(file)
        return fh
    except Exception as e:
        print("打开文件错误：" + e)


# 根据excel名以及第几个标签信息就可以得到具体标签的内容
def get_file_value(filename, sheetnum):
    rvalue = []
    fh = open_xls(filename)
    sheet = fh.sheets()[sheetnum]
    row_num = sheet.nrows
    for rownum in range(0, row_num):
        rvalue.append(sheet.row_values(rownum))
    return rvalue


if __name__ == "__main__":
    count = 0
    while count < len(find_pdf_files()):
        path = find_pdf_files()[count]
        file_path_dict = is_file_or_dir(path)
        page_dict = file_name_analysis(file_path_dict)
        pdf_data = load_pdf(page_dict)
        # print(find_ones_xlsx())
        count = count + 1
