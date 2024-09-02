- 修正点詳細
	- refact-hkoizumiブランチは、mainブランチから分岐している
	1. ft_sort.c, ft_rotate_type.cの中身
		- 上記2ファイル内の関数は、しおりさん(syonekur)による大改修入ってます(それに伴って.hファイル内も一部修正)
	2. コメントについて
		- "// !!!! "で始まっているコメントは、致命的な欠陥があるため必ず修正するべき箇所
			- " -> 修正済み"の場合、基本的には付近にある"// 追加"の行が修正(追加)したもの
			- " -> 未修正"の場合は、適宜修正する必要あり
		- "// !!! "で始まっているコメントは、通常の実行に関しては問題ないが、提出前には修正すべき箇所
			- 冗長なコード、コマンドライン引数が想定外のフォーマットをしている際にエラーが起き得るコード、等
		- "// !! "で始まっているコメントは、tips、推奨事項、メモ、等
- 見落としがある可能性は十分にあるため悪しからず(hkoizumi)