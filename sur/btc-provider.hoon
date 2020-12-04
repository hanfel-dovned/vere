/-  *btc
|%
+$  host-info  [api-url=@t connected=? clients=(set ship)]
+$  req-id  @t
+$  command
  $%  [%set-credentials api-url=@t]
      [%whitelist-clients clients=(set ship)]
  ==
+$  action  [=req-id body=action-body]
+$  action-body
  $%  [%address-info =address]
      [%raw-tx =txid]
      [%ping ~]
  ==
+$  result  [=req-id body=result-body]
+$  result-body
  $%  [%address-info utxos=(set utxo) used=? block=@ud]
      [%raw-tx =txid =rawtx]
  ==
+$  error
  $%  [%not-connected status=@ud]
      [%bad-request status=@ud]
      [%no-auth status=@ud]
      [%http-error status=@ud]
      [%rpc-error ~]
  ==
+$  update  (each result error)
+$  status
  $%  [%connected block=@ud fee=@ud]
      [%disconnected ~]
  ==
::
++  rpc
  |%
  +$  action

    $%  [%get-address-info =address]
        [%get-raw-tx =txid]
        [%get-block-count ~]
        [%get-block-and-fee ~]
    ==
  :: 
  +$  response
    $%  [%get-address-info utxos=(set utxo) used=? block=@ud]
        [%create-psbt psbt=cord]
        [%get-raw-tx =txid =rawtx]
        [%get-block-count block=@ud]
        [%get-block-and-fee block=@ud fee=sats]

    ==
  --
--
::
