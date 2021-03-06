diff -urN einstein-2.0.orig/formatter.cpp einstein-2.0/formatter.cpp
--- formatter.cpp	2005-08-13 22:40:58.000000000 -0400
+++ formatter.cpp	2006-08-15 11:18:28.000000000 -0400
@@ -58,7 +58,7 @@
             if ((c.type == INT_ARG) || (c.type == STRING_ARG) ||
                     (c.type == FLOAT_ARG) || (c.type == DOUBLE_ARG))
             {
-                int no = (int)c.data;
+                long int no = (long int)c.data;
                 args[no - 1] = c.type;
             }
         }
@@ -123,7 +123,7 @@
 std::wstring Formatter::format(std::vector<ArgValue*> &argValues) const
 {
     std::wstring s;
-    int no;
+    long int no;
 
     for (int i = 0; i < commandsCnt; i++) {
         Command *cmd = &commands[i];
@@ -135,8 +135,8 @@
                 
             case STRING_ARG:
             case INT_ARG:
-                no = (int)cmd->data - 1;
-                if (no < (int)argValues.size())
+                no = (long int)cmd->data - 1;
+                if (no < (long int)argValues.size())
                     s += argValues[no]->format(cmd);
                 break;
