from lxml import etree
import re
import sys

import merge
import stopwords
import stemming


# RegEx Compiler
redirect_pattern = re.compile("#REDIRECT", re.I)
disambiguation_pattern = re.compile("\{\{" + "disambig" + "\}\}", re.I)
stub_pattern = re.compile("\-" + "stub" + "\}\}", re.I)

styles_pattern = re.compile("\{\|.*?\|\}$", re.M | re.S)
curly_cleanup_pattern0 = re.compile("^\{\{.*?\}\}$", re.M | re.S)
curly_cleanup_pattern1 = re.compile("\{\{.*?\}\}", re.M | re.S)
ref_pattern = re.compile("<ref>.*?</ref>", re.M | re.S)
comments_cleanup_pattern = re.compile("<!--.*?-->", re.M | re.S)

tag_pattern = re.compile("<.*>")
http_pattern0 = re.compile("http.*[ ]")
http_pattern1 = re.compile("http.*[\n]")
special_char_pattern = re.compile("[^A-Za-z0-9' ]")
apostrophe_pattern = re.compile("[']")
# pure_numeric_pattern = re.compile("[0-9]+")
# square_cleanup_pattern0 = re.compile("^\[\[.*?:.*?\]\]$")
# square_cleanup_pattern1 = re.compile("\[\[(.*?)\]\]")
infobox_pattern = re.compile("\{\{Infobox.*?\}\}", re.M | re.S | re.I)
remove_infobox_pattern = re.compile("infobox", re.I)
category_pattern = re.compile("\[\[Category:.*\]\]", re.M | re.S | re.I)
remove_category_pattern = re.compile("category", re.I)
link_pattern = re.compile("\[\[.*?\]\]")
references_pattern = re.compile("== References(?s)(?:(?!\n\n).)*")
remove_references_pattern = re.compile("references", re.I)


def clean(text):
    text = re.sub(redirect_pattern, "", text)
    text = re.sub(disambiguation_pattern, "", text)
    text = re.sub(stub_pattern, "", text)

    text = re.sub(styles_pattern, "", text)
    text = re.sub(curly_cleanup_pattern0, "", text)
    text = re.sub(curly_cleanup_pattern1, "", text)
    text = re.sub(ref_pattern, "", text)
    text = re.sub(comments_cleanup_pattern, "", text)

    text = re.sub(tag_pattern, "", text)
    text = re.sub(http_pattern0, "", text)
    text = re.sub(http_pattern1, "", text)
    text = re.sub(special_char_pattern, " ", text)
    text = re.sub(apostrophe_pattern, "", text)
    # text = re.sub(pure_numeric_pattern, "", text)
    return text


def stemmer(tokens, new_tokens):
    for i in tokens:
        if i not in stopwords.dict:
            new_tokens.append(stemming.stem(i))
    return new_tokens


prefix = 'http://www.mediawiki.org/xml/export-0.8/'


def get_id(elem):
    id_elem = elem.xpath('.//x:id', namespaces={'x': prefix})
    return id_elem[0].text


def get_title(elem):
    title_elem = elem.xpath('.//x:redirect/@title', namespaces={'x': prefix})
    if title_elem:
        title_text = title_elem[0]
    else:
        title_elem = elem.xpath('.//x:title', namespaces={'x': prefix})
        title_text = title_elem[0].text

    title_tokens = clean(title_text).lower().split()
    new_title_tokens = []
    new_title_tokens = stemmer(title_tokens, new_title_tokens)
    return new_title_tokens


def get_text(elem):
    text_elem = elem.xpath('.//x:text', namespaces={'x': prefix})
    text = text_elem[0].text

    # Infobox
    #########
    infobox_list = re.findall(infobox_pattern, text)
    text = re.sub(infobox_pattern, " ", text)
    new_infobox_tokens = []
    infobox_text = ' '.join(infobox_list)

    infobox_text = re.sub(http_pattern0, " ", infobox_text)
    infobox_text = re.sub(http_pattern1, " ", infobox_text)
    infobox_text = re.sub(special_char_pattern, " ", infobox_text)
    infobox_text = re.sub(apostrophe_pattern, "", infobox_text)
    # infobox_text = re.sub(pure_numeric_pattern, " ", infobox_text)
    infobox_text = re.sub(remove_infobox_pattern, "", infobox_text)
    infobox_tokens = infobox_text.lower().split()
    new_infobox_tokens = stemmer(infobox_tokens, new_infobox_tokens)
    # print(Counter(new_infobox_tokens))

    # Category
    ##########
    category_list = re.findall(category_pattern, text)
    text = re.sub(category_pattern, " ", text)
    new_category_tokens = []
    category_text = ' '.join(category_list)

    category_text = re.sub(http_pattern0, " ", category_text)
    category_text = re.sub(http_pattern1, " ", category_text)
    category_text = re.sub(comments_cleanup_pattern, " ", category_text)
    category_text = re.sub(special_char_pattern, " ", category_text)
    category_text = re.sub(apostrophe_pattern, "", category_text)
    # category_text = re.sub(pure_numeric_pattern, " ", category_text)
    category_text = re.sub(remove_category_pattern, " ", category_text)
    category_tokens = category_text.lower().split()
    new_category_tokens = stemmer(category_tokens, new_category_tokens)
    # print(Counter(new_category_tokens))

    # Link
    ######
    link_list = re.findall(link_pattern, text)
    text = re.sub(link_pattern, " ", text)
    new_link_tokens = []
    link_text = ' '.join(link_list)

    link_text = re.sub(http_pattern0, " ", link_text)
    link_text = re.sub(http_pattern1, " ", link_text)
    link_text = re.sub(special_char_pattern, " ", link_text)
    link_text = re.sub(apostrophe_pattern, "", link_text)
    # link_text = re.sub(pure_numeric_pattern, " ", link_text)
    link_tokens = link_text.lower().split()
    new_link_tokens = stemmer(link_tokens, new_link_tokens)
    # print(Counter(new_link_tokens))

    # Link 2 == External Links ==
    ########

    # References
    references_list = re.findall(references_pattern, text)
    text = re.sub(references_pattern, " ", text)
    new_references_tokens = []
    references_text = ' '.join(references_list)

    references_text = re.sub(curly_cleanup_pattern0, " ", references_text)
    references_text = re.sub(curly_cleanup_pattern1, " ", references_text)
    references_text = re.sub(http_pattern0, " ", references_text)
    references_text = re.sub(http_pattern1, " ", references_text)
    references_text = re.sub(special_char_pattern, " ", references_text)
    references_text = re.sub(apostrophe_pattern, "", references_text)
    # references_text = re.sub(pure_numeric_pattern, " ", references_text)
    references_text = re.sub(remove_references_pattern, " ", references_text)
    references_tokens = references_text.lower().split()
    new_references_tokens = stemmer(references_tokens, new_references_tokens)
    # print(Counter(new_references_tokens))

    text_tokens = clean(text).lower().split()
    new_text_tokens = []
    new_text_tokens = stemmer(text_tokens, new_text_tokens)
    # print(Counter(new_text_tokens))
    return [new_infobox_tokens, new_category_tokens, new_link_tokens,
            new_references_tokens, new_text_tokens]


def final_func(wiki_dump, output):
    file_name = wiki_dump
    out_file = open(output, "w")
    context = etree.iterparse(file_name, events=('end', ),
                              tag='{http://www.mediawiki.org/xml/export-0.8/}page')

    final_array = []

    for event, elem in context:
        doc_id = get_id(elem)
        title_tokens = get_title(elem)
        token_list = get_text(elem)

        final_dict = {}  # word: [title 0, info 1, category 2, link 3, ref 4, body 5]
        # Title
        for i in title_tokens:
            if i in final_dict:
                final_dict[i][0] += 1
            else:
                final_dict[i] = [1, 0, 0, 0, 0, 0]
        # Infobox
        for i in token_list[0]:
            if i in final_dict:
                final_dict[i][1] += 1
            else:
                final_dict[i] = [0, 1, 0, 0, 0, 0]
        # Category
        for i in token_list[1]:
            if i in final_dict:
                final_dict[i][2] += 1
            else:
                final_dict[i] = [0, 0, 1, 0, 0, 0]
        # Link
        for i in token_list[2]:
            if i in final_dict:
                final_dict[i][3] += 1
            else:
                final_dict[i] = [0, 0, 0, 1, 0, 0]
        # Ref
        for i in token_list[3]:
            if i in final_dict:
                final_dict[i][4] += 1
            else:
                final_dict[i] = [0, 0, 0, 0, 1, 0]
        # Body
        for i in token_list[4]:
            if i in final_dict:
                final_dict[i][5] += 1
            else:
                final_dict[i] = [0, 0, 0, 0, 0, 1]

        for key in final_dict:
            temp_list = final_dict[key]

            temp_str = key + ':' + doc_id + '-'
            if temp_list[0] != 0:
                temp_str += 't' + str(temp_list[0])
            if temp_list[1] != 0:
                temp_str += 'i' + str(temp_list[1])
            if temp_list[2] != 0:
                temp_str += 'c' + str(temp_list[2])
            if temp_list[3] != 0:
                temp_str += 'l' + str(temp_list[3])
            if temp_list[4] != 0:
                temp_str += 'r' + str(temp_list[4])
            if temp_list[5] != 0:
                temp_str += 'b' + str(temp_list[5])
            final_array.append(temp_str)

        elem.clear()
        while elem.getprevious() is not None:
            del elem.getparent()[0]

    ans = merge.merge_sort_parallel(final_array)
    out_file.write('\n'.join(ans))


final_func(sys.argv[1], sys.argv[2])
