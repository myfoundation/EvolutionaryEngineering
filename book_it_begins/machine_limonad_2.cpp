void machine_logic(int in_signal)
{
    /* Диспетчер входа в фазу (State Entry Dispatcher) */
    if (state == S0) goto L_S0;
    if (state == S1) goto L_S1;
    if (state == S2) goto L_S2;
    if (state == S3) goto L_S3;
    return;

L_S0:
{
    if (in_signal == 'M')
    {
        process_step(S1, A0);
        return;
    }
    if (in_signal == 'V')
    {
        process_step(S3, A3);
        return;
    }
    if (in_signal == 'T')
    {
        process_step(S0, A4);
        return;
    }
    if (in_signal == 'P')
    {
        process_step(S0, A2);
        return;
    }
    if (in_signal == 'O')
    {
        process_step(S0, A4);
        return;
    }
    return;
}

L_S1:
{
    if (in_signal == 'M')
    {
        process_step(S2, A0);
        return;
    }
    if (in_signal == 'V')
    {
        process_step(S3, A3);
        return;
    }
    if (in_signal == 'T')
    {
        process_step(S0, A1);
        return;
    }
    if (in_signal == 'P')
    {
        process_step(S1, A2);
        return;
    }
    if (in_signal == 'O')
    {
        process_step(S0, A7);
        return;
    }
    return;
}

L_S2:
{
    if (in_signal == 'M')
    {
        process_step(S0, A5);
        return;
    }
    if (in_signal == 'V')
    {
        process_step(S3, A3);
        return;
    }
    if (in_signal == 'T')
    {
        process_step(S0, A1);
        return;
    }
    if (in_signal == 'P')
    {
        process_step(S2, A2);
        return;
    }
    if (in_signal == 'O')
    {
        process_step(S0, A7);
        return;
    }
    return;
}

L_S3:
{
    if (in_signal == 'M')
    {
        process_step(S3, A6);
        return;
    }
    if (in_signal == 'V')
    {
        process_step(S3, A6);
        return;
    }
    if (in_signal == 'T')
    {
        process_step(S3, A6);
        return;
    }
    if (in_signal == 'P')
    {
        process_step(S3, A6);
        return;
    }
    if (in_signal == 'O')
    {
        process_step(S3, A6);
        return;
    }
    return;
}

}
