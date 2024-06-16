# APCS 6月份(2024) 實作題題解

## 前言
此份題解皆以高中生程式解題系統的題目為準，AC程式碼僅代表能通過ZJ上的題目，不代表能在APCS考場有一模一樣的表現。

## 程式碼
https://github.com/YummyBerry1108/House-of-Codes/tree/main/Zerojudge/APCS/2024_06_16

##  1. 特技表演
https://zerojudge.tw/ShowProblem?problemid=o076

從左往右看，如果左大於右就路徑長加1
否則重設路徑長從下一棟大樓開始看
每次循環取max最後輸出

##  2. 電子畫布
https://zerojudge.tw/ShowProblem?problemid=o077

照題敘開一個二維陣列，對每筆操作都遍歷一次陣列，只要該位置曼哈頓距離小於`t`就加上`x`

最後輸出即可

##  3. 缺字問題
https://zerojudge.tw/ShowProblem?problemid=o078

觀察範圍發現全暴力大概在5e6附近，應該沒啥問題

把`s`每個長度`l`的子字串丟到unordered_map裡，然後照字典序DFS
第一個不在unordered_map的就是答案

## 4. 最佳選擇
https://zerojudge.tw/ShowProblem?problemid=o079

觀察：
1. 操作順序不影響 
ex: 左拿3 + 右拿1 等於 左拿2 + 右拿1 + 左拿1
2. 可以O(n)處理的有：前綴後綴的總和、奇數數量、偶數數量
根據此兩觀察可以寫一個O(n²)解，20分

3. 設奇數-1 偶數+1(奇偶差) 當前綴為n時，要找到後綴為-n的才滿足奇偶一樣的條件
4. 當前綴為n時，可以對所有後綴為-n的做二分搜
5. 枚舉所有前綴，然後作二分搜取max，時間複雜度O(n log n)
最後可得滿分解

# 後記
這次前三題都挺直觀簡單的，而且居然沒DP，難度都塞到第四題去了。但是我覺得第四題超有趣，不過好像看過類似的套路就是了