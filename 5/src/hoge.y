
/* 以下は parser.y のコードの一部 */
expression
        : term
        | PLUS term
        | MINUS term
        {
          LLVMcode *tmp;             /* 生成した命令へのポインタ */
          Factor arg0, arg1, retval; /* 加算の引数・結果 */
          tmp = (LLVMcode *)malloc(sizeof(LLVMcode)); /*メモリ確保 */
          tmp->next = NULL;          /* 次の命令へのポインタを初期化 */
          tmp->command = Add;        /* 命令の種類を加算に設定 */
          arg2 = factorpop();        /* スタックから第2引数をポップ */
          arg1 = factorpop();        /* スタックから第1引数をポップ */
          retval.type = LOCAL_VAR;   /* 結果を格納するレジスタは局所 */
          retval.val = cntr;         /* 新規のレジスタ番号を取得 */
          cntr ++;                   /* カウンタをインクリメント */
          (tmp->args).add.arg1 = arg1; /* 命令の第1引数を指定 */
          (tmp->args).add.arg2 = arg2; /* 命令の第2引数を指定 */
          (tmp->args).add.retval = retval; /* 結果のレジスタを指定 */
          if( codetl == NULL ){ /* 解析中の関数の最初の命令の場合 */
            if( decltl == NULL ){   /* 解析中の関数がない場合 */
              /* 関数宣言を処理する段階でリストが作られているので，ありえない */
              fprintf(stderr,"unexpected error\n");
            }
            decltl->codes = tmp;   /* 関数定義の命令列の先頭の命令に設定 */
            codehd = codetl = tmp; /* 生成中の命令列の末尾の命令として記憶 */
          } else { /* 解析中の関数の命令列に1つ以上命令が存在する場合 */
            codetl->next = tmp; /* 命令列の末尾に追加 */
            codetl = tmp;       /* 命令列の末尾の命令として記憶 */
          }
          factorpush( retval ); /* 加算の結果をスタックにプッシュ */
        }
        | expression PLUS term
        | expression MINUS term
        ;
