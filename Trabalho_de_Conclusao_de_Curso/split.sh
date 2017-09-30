for stream in `tshark -r $1 -T fields -e tcp.stream | sort -n | uniq`
do
    echo $stream
    tshark -r $1 -w stream-$stream.cap -Y "tcp.stream==$stream"
    tshark -r "stream-$stream.cap" -q -z io,stat,1,"SUM(tcp.len)tcp.len","SUM(tcp.hdr_len)tcp.hdr_len","AVG(tcp.analysis.ack_rtt)tcp.analysis.ack_rtt","COUNT(tcp.analysis.spurious_retransmission)tcp.analysis.spurious_retransmission","COUNT(tcp.analysis.retransmission)tcp.analysis.retransmission" > "medidas_$stream.txt"
    tshark -r stream-$stream.cap -t ad > saida_$stream.txt
    rm stream-$stream.cap
done
