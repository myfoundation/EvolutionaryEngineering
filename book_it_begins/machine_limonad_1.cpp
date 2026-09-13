void machine_logic(int in_signal)
{
    switch (state)
    {
        case S0:
        {
            switch (in_signal)
            {
                case 'M':
                {
                    process_step(S1, A0);
                    break;
                }
                case 'V':
                {
                    process_step(S3, A3);
                    break;
                }
                case 'T':
                {
                    process_step(S0, A4);
                    break;
                }
                case 'P':
                {
                    process_step(S0, A2);
                    break;
                }
                case 'O':
                {
                    process_step(S0, A4);
                    break;
                }
            }
            break;
        }
        case S1:
        {
            switch (in_signal)
            {
                case 'M':
                {
                    process_step(S2, A0);
                    break;
                }
                case 'V':
                {
                    process_step(S3, A3);
                    break;
                }
                case 'T':
                {
                    process_step(S0, A1);
                    break;
                }
                case 'P':
                {
                    process_step(S1, A2);
                    break;
                }
                case 'O':
                {
                    process_step(S0, A7);
                    break;
                }
            }
            break;
        }
        case S2:
        {
            switch (in_signal)
            {
                case 'M':
                {
                    process_step(S0, A5);
                    break;
                }
                case 'V':
                {
                    process_step(S3, A3);
                    break;
                }
                case 'T':
                {
                    process_step(S0, A1);
                    break;
                }
                case 'P':
                {
                    process_step(S2, A2);
                    break;
                }
                case 'O':
                {
                    process_step(S0, A7);
                    break;
                }
            }
            break;
        }
        case S3:
        {
            switch (in_signal)
            {
                case 'M':
                {
                    process_step(S3, A6);
                    break;
                }
                case 'V':
                {
                    process_step(S3, A6);
                    break;
                }
                case 'T':
                {
                    process_step(S3, A6);
                    break;
                }
                case 'P':
                {
                    process_step(S3, A6);
                    break;
                }
                case 'O':
                {
                    process_step(S3, A6);
                    break;
                }
            }
            break;
        }
    }
}
