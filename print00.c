int _printf(const char *format, ...)

{

    va_list arg;

    int done;

    va_start(arg, format);

    done = vfprintf(stdout, format, arg);

    

    return(done);

} 
