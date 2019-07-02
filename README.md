# Keywords Extraction
## The Influence Of User Review On Software Quality Design Based On A Game Application

Our research topic is the impact of user comments on software quality design based on a game application. The so-called software quality refers to the extent to which the software is consistent with clearly and implicably defined requirements. Our research is divided into five influencing factors: correctness, robustness, reliability, performance and maneuverability. In order to explore the importance of these five influencing factors on software quality, we collect a large number of feedback from user comments for a game application. At the same time, a program for keyword extraction of text information for a large number of comments is designed, and the keyword extraction is carried out to arrange the hot words in the user comments. We also design the thesaurus, match the hot words with the information in the thesaurus, classify them according to the influencing factors of software quality corresponding to keywords, and arrange them in turn according to the importance. Then the results are analyzed, and the main factors affecting the quality of software are obtained.

我们研究的课题为基于某游戏应用的用户评论对于软件质量设计的影响。所谓的软件质量是指“软件与明确地和隐含地定义的需求相一致的程度”。针对于我们的研究主要分为了正确性、健壮性、可靠性、性能以及可操作性这五个影响因素。为了探究这五个影响因素对于软件质量影响的重要性，我们针对于某个游戏应用进行了数据采集，收集了大量的用户评论的反馈。同时设计了对于大量评论的文本信息关键词提取的程序，对其进行关键词的提取，排列出用户评论中出现的热点词。我们也针对性地设计了词库，将热点词与词库中的信息相匹配，根据关键词对应的软件质量影响因素进行分类，将其按照重要性依次排列。进而分析其结果，得出影响软件质量的主要因素。

## Project Members

* Qi Changhang 齐昌航
* Liang Zhenxuan 梁振轩
* Liu Yuanhao 刘源灏
* Wang Hai 王海


## Background

Our group discussed the topic of keyword extraction and found some problems in software applications in the market, that is, whether the comments of users can reflect the problems of software design. Therefore, we refer to the data and determine the influencing factors of software quality.

我们组在关键字提取的课题上进行了讨论，发现市场上软件应用的部分问题，即用户的评论能否反映出软件的设计上问题。因此我们查阅了资料，确定了在于软件质量的影响因素上的研究。

## Research ideas

Our main idea is to collect the comments of software applications, and then sort them out and extract and save the keywords. The main principle is to adopt the Shannon entropy difference between the internal pattern and the external pattern. The preserved keywords are matched with the established lexical contents, and then the importance of the software quality factors is analyzed according to the proportion of the keywords in order according to the matching degree.

我们主要的思路是对软件应用的评论进行收集，随后将其整理并进行关键字的提取工作并保存，其中主要原理为采用了内在模式和外部模式之间的Shannon熵差。将保存下来的关键字与建立好的词库内容进行匹配，进而按照匹配度依次排列，按照占比重的不同分析出软件质量因素中的重要程度。


## Highlights

In the establishment of the thesaurus, we first collected some information on the Internet, but did not find the lexicon information that can meet our requirements, so we decided to sum up and establish the thesaurus ourselves. The specific method is that we collect more than 20 software applications of the same type, obtain nearly 10,000 user comment information, and extract keywords respectively. All the keywords were screened and classified under the five kinds of software quality factors. Then we use our own vocabulary and test samples to test, and effectively get a lot of keyword information, which can be classified and applied.

在对于词库的建立上，我们先是在网上搜集了部分信息，但并没有找到很能符合我们要求的词库信息，因此我们决定自己总结建立词库。具体方法是：我们搜集超过20个同类型的软件应用，获取了近万条的用户评论信息，将其分别进行关键词的提取。将所有得到的关键词进行筛选，并将其分别归入到我们定好的五类软件质量因素之下。随后用我们自主建立的词库与测试样例进行测试，有效得到了许多关键词的信息，能够将其进行分类应用。

## Please Note

If you use the keyword extraction software or dynamic link library (dll) in your program or research, please indicate that the part of paper and program cites the following paper.

Zhen YANG, Jianjun LEI, Kefeng FAN, Yingxu LAI. Keyword Extraction by Entropy Difference between the Intrinsic and Extrinsic Mode, Physica A: Statistical Mechanics and its Applications, 392 (2013), 4523-4531. 
http://dx.doi.org/10.1016/j.physa.2013.05.052

## Special reference

The experimental results of our group refer to the following resources：
https://github.com/fromskyblue/Keywords-Extraction

## Video Demonstration

We recorded the video in a specific way of doing it and put it at the following address:
https://www.bilibili.com/video/av57577972/
