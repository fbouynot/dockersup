FILE *pp;
if ((pp = popen("ps aux", "r") == NULL)
{ perror("popen");
    exit(1);
}
while (fgets(buf, sizeof(buf), pp))
fputs(buf, stdout);
pclose(pp);